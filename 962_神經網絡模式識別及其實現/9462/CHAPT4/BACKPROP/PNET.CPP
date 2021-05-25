
#define NEURONHIGH   1.0               // Neuron's high output value
#define NEURONLOW    0.0               // Neuron's low output value
#define TRUE           1
#define FALSE          0

class WEIGHT;                               // Forward reference

// ***** #DEFINEs for the NetFileData class *****

#define MAXLAYERS    6                 // Max # of layers permitted in network

// ***** Defined structures & classes *****

struct WEIGHTIMAGE
{
  double      data;                         // Weight value
  int         sneuron;                      // Source neuron for this weight
  int         dneuron;                      // Dest neuron for this weight
  WEIGHTIMAGE *next;
};

struct NETRESULTS
{
  int           index;                      // Neurons identification number
  double        value;                      // Neurons output value
  char          character;                  // char representation of digit
};

class NETFILEDATA
{
private:
  double      temperature;                // Neurons temperature
  double      threshold;                  // Neurons firing threshold
  int         Nlayers;                    // Number of layers in the net
  int         neurons[MAXLAYERS];         // Number of neurons per layer
  int         status;                     // Error status ( 0 = OK)
  WEIGHTIMAGE *weights[MAXLAYERS - 1];    // Forced into another Linked-List

  void        ADDweights(int l, int d, int s, double w);
  double      GETweights(int l, int d, int s);

public:
  NETFILEDATA(void);
  int    SetupNet(char *);
  double GetTemp(void) { return temperature; }
  double GetThresh(void) { return threshold; }
  int    GetNlayers(void) { return Nlayers; }
  int    GetLayerSize(int layer) { return neurons[layer]; }
  double GetWeight(int l, int d, int s) { return GETweights(l-1, d, s); }
  int    GetStatus(void) { return status; }
};

NETFILEDATA::NETFILEDATA(){
   int i;
for (i=0; i<(MAXLAYERS-1); i++) {
   weights[i]= (WEIGHTIMAGE *)NULL;
   } /* endfor */
}

int NETFILEDATA::SetupNet(char *wgt_file_name)
{
  FILE   *wgt_file_ptr;                     // Pointer to a weight file
  double AWeight;                           // Used to hold a temporary weight

  if((wgt_file_ptr = fopen(wgt_file_name, "r")) == NULL)
    return 1;

  fscanf(wgt_file_ptr, "%lg", &threshold);     // Read in threshold value
  fscanf(wgt_file_ptr, "%lg", &temperature);   // Read in temperature value
  fscanf(wgt_file_ptr, "%d", &Nlayers);        // Read in # of layers

  for(int j = 0; j < MAXLAYERS; j++)
    neurons[j] = 0;                            // Initialize array to zero

  for(int i = 0; i < Nlayers; i++)
    fscanf(wgt_file_ptr, "%d", &neurons[i]);   // Read # neurons in each layer

  for(int lyr = 1; lyr < Nlayers; lyr++)       // Traverse all layers
    {
      for(int dn = 0; dn < neurons[lyr]; dn++) // Traverse dest layer nodes
        {                                             // Pick up bias neuron
          for(int sn = 0; sn <= neurons[lyr-1]; sn++) // Traverse src lyr nodes
            {
            //Read in the weight from the weight file 
            fscanf(wgt_file_ptr, "%lg", &AWeight); 
            ADDweights(lyr-1, dn, sn, AWeight); // Add new weight to the net
            }
        }
    }
  fclose(wgt_file_ptr);                        // Close the weight file

  return 0;
}

void NETFILEDATA::ADDweights(int l, int d, int s, double w)
{
  WEIGHTIMAGE *WI   = weights[l],             //Point to weights for this layer
              *Wnew = new WEIGHTIMAGE,        //Create a new weight
              *cursor,
              *trailer;

  Wnew->data    = w;                           // Assign Wnew with
  Wnew->dneuron = d;                           //       the information
  Wnew->sneuron = s;                           //           that was passed in
  Wnew->next    = (WEIGHTIMAGE *)NULL;
  if(WI)
    {
      cursor  = WI;
      trailer = (WEIGHTIMAGE *)NULL;
      while(cursor)
        {
          trailer = cursor;
          cursor  = cursor->next;
        }
      trailer->next = Wnew;
    }
  else
      weights[l] = Wnew;
}

double NETFILEDATA::GETweights(int l, int d, int s)
{
  WEIGHTIMAGE *WI = weights[l]; // Point to 1st weight in the current layer

  while(WI)
    {
      if((WI->sneuron == s) && (WI->dneuron == d))
        {
          status = 0;
          return WI->data;
        }
      WI = WI->next;
    }
//  printf("GETweights ERROR EXIT -- WEIGHT NOT FOUND\n");
  status = 1;
  return 0.0;
}


class NEURON
{
private:
  static double temperature;        // Holds a single copy for all the neurons 
  static double threshold;          // Holds a single copy for all the neurons 
  int           id;                 // Holds a neuron identification number
  double        out;                // Holds a neurons output value
  WEIGHT        *weight1;           // Pointer to list of weights (head)
  WEIGHT        *weightL;           // Pointer to list of weights (tail)
  int           BiasFlg;            // 1 = Bias Neuron,  0 otherwise
  NEURON        *next;              // Hook to allow neurons to be list members

public:
  NEURON(void) { id = 0; out = 0; 
                 weight1 = (WEIGHT *)NULL; next = (NEURON *)NULL; }
  NEURON(int ident, int bias=0) { id = ident; out = 0; BiasFlg=bias;
                      weight1 = (WEIGHT *)NULL; next = (NEURON *)NULL; }

  void   calc(void);                     // Update out based on weights/inputs
  void   SetNext(NEURON *N) { next = N; }
  NEURON *GetNext(void) { return next; }
  void   SetWeight(double Wght, NEURON *SrcPtr);
  int    GetId(void) { return id; }
  double GetOut(void) { return out; }
  void   SetTemperature(double tmpr) { temperature = tmpr; }
  void   SetThreshold(double thrsh) { threshold = thrsh; }
  void   SetOut(double val) { out = val; }
  int    IsBias(){return BiasFlg;}
};


double NEURON::temperature = 0.0;      // REQUIRED for static data elements
double NEURON::threshold   = 0.0;      

class WEIGHT
{
private:
  NEURON *SRCneuron;                   // Source neuron for this weight
  double WtVal;                        // Magnitude of weight
  WEIGHT *next;                        // Hook so weights can be list members

public:
  WEIGHT(double W, NEURON *SN) { next = (WEIGHT *)NULL; 
                                 SRCneuron = SN; WtVal = W; }
  NEURON *GetSRCNeuron(void) { return SRCneuron; }
  double getWeight(void) { return WtVal; }
  void   SetNext(WEIGHT *W) { next = W; }
  WEIGHT *GetNext(void) { return next; }
};

void NEURON::SetWeight(double Wght, NEURON *SrcPtr)
{
  WEIGHT *W = new WEIGHT(Wght, SrcPtr);

  if(weight1 == NULL)
    {
      weight1 = weightL = W;
    }
  else
    {
      weightL->SetNext(W);
      weightL = W;
    }
}

void NEURON::calc(void)
{
  NEURON *Nptr;                     // Pointer to neuron

  WEIGHT *Wptr = weight1;           // Pointer to the first weight in the layer

  double NET   = 0.0,               // Accumulates the sum
         PLNout,                    // Previous layer neuron output
         Weight;                    // Connection strength

  if (!BiasFlg) {
     while(Wptr)                    // Traverse src layer & weights
       {
       Weight = Wptr->getWeight();
       Nptr   = Wptr->GetSRCNeuron();// Get weight between prev/curr layer
       PLNout = Nptr->GetOut();      // Get the previous layer output (out)
       NET   += Weight * PLNout;     // Sum(weight * out)  over the curr layer
       Wptr   = Wptr->GetNext();     // Get the next weight in the weight list
       }
     // Calculate a neuron output using a sigmoid
     out = 1 / (1 + exp(- (NET + threshold)/temperature));
     }
   else {
     out = 1.0;                         // force output on for bias neuron
     }
}

class LAYER
{
private:
  int          LayerID;              // 0 for input, 1 for 1st hidden,...
  unsigned int Ncount;               // # of neurons in layer;
  NEURON       *Neuron1;             // Pointer to 1st neuron in layer
  NEURON       *NeuronL;             // Pointer to last neuron in layer
  LAYER        *next;                // Hook so layers can be list members

public:
  LAYER(int layer_id, NETFILEDATA *netdata);
  int          SetWeights(NEURON *PrevNeuron, NETFILEDATA *netdata);
  void         SetNext(LAYER *Nlayer) { next = Nlayer; }
  int          GetLayerID(void) { return LayerID; }        
  NEURON       *GetFirstNeuron() { return Neuron1; }
  LAYER        *GetNext(void) { return next; }
  unsigned int getCount(void) { return Ncount; }
  void         calc(int);
};


LAYER::LAYER(int layer_id, NETFILEDATA *netdata)
{
  NEURON *Nptr;

  LayerID = layer_id;
  Neuron1 = NeuronL = (NEURON *)NULL;
  next    = (LAYER *)NULL;

  //Get # of neurons in layer #layer_id
  Ncount = netdata->GetLayerSize(layer_id); 

  for(int i = 0; i <= Ncount; i++)    // include bias
    {
      if (i==Ncount) {
         Nptr = new NEURON(i,TRUE);   // This is a bias Neuron
         }
       else {
         Nptr = new NEURON(i);        // This is a normal Neuron
         } /* endif */

      // Attach neuron to the list
      if(Neuron1 == NULL)
        {
          Neuron1 = NeuronL = Nptr;
        }
      else
        {
          NeuronL->SetNext(Nptr);
          NeuronL = Nptr;
        }
    }
}

void LAYER::calc(int out_layer)
{
  NEURON *Nptr = Neuron1;
 
  while(Nptr)                    // Traverse the layer
    {
    Nptr->calc();                // Ask the neuron to calculate its own value
    Nptr = Nptr->GetNext();      // Move to next neuron in the layer
    }
}

int LAYER::SetWeights(NEURON *PrevNeuron, NETFILEDATA *netdata)
{
  NEURON *CurNeuron = Neuron1,
         *PrevPtr;
  double ZWeight = 0.0;
  int    curx = 0,                    // Current layer neuron index
         prevx,                       // Previous layer neuron index
         status = 0;                  // Error status ( 0 = ok)

  
  while(CurNeuron != NULL)           //Traverse curr lyr starting at 1st neuron
    {
      if ( !CurNeuron->IsBias()) {     // Bias neurons dont have incomming wgts
         PrevPtr = PrevNeuron;           // Pointer to 1st neuron in prev layer
         prevx   = 0;                    // Index of 1st neuron in prev layer
         while(PrevPtr)                  // Read a weight from the file
           {
             ZWeight = netdata->GetWeight(LayerID, curx, prevx++);
             status = netdata->GetStatus();
             if(status > 0)
               return status;
             CurNeuron->SetWeight(ZWeight, PrevPtr);
             PrevPtr = PrevPtr->GetNext();
           }
         }
      curx++;                           // Bump index to next for current layer
      CurNeuron = CurNeuron->GetNext(); // Set pointer to next for current layer
    }
  return status;
}

class NETWORK
{
private:
  int           Alive;
  NETFILEDATA   netdata;
  int           Nlayers;
  LAYER         *INlayer;
  LAYER         *OUTlayer;
  NETWORK       *next;                  // Need more than 1 network ... OK

public:
  NETWORK(void) { Alive = 0; next=(NETWORK *)NULL; }
  int    Setup(char *);
  void   ApplyVector(unsigned char *, int);
  void   RunNetwork(void);
  int    RequestNthOutNeuron(int, NETRESULTS *);
  double RequestTemp(void);
  double RequestThresh(void);
  int    RequestLayerSize(int);
  int    GetAlive() { return Alive; }
  NETWORK *GetNext() {return next;}
  void    SetNext(NETWORK *netptr) {next=netptr;}
private:
  int    SetWeights(void);

};

int NETWORK::Setup(char *wgt_file_name)
{

  LAYER  *Lptr;                         // Pointer to a layer
  NEURON N;             // Use to set statics (temp. & thres. for NEURON class)
  int status = 0;                       // Error Status > 0 if error occured
  char   *tbl_file_name;                // holds the table file name

  // Setup network using info in the weight file 
  status = netdata.SetupNet(wgt_file_name); 
  if(status > 0)                        // error occured opening weight file
    return 1;
 
  Nlayers  = netdata.GetNlayers();       // Get the number of layers

  N.SetTemperature(netdata.GetTemp());   // Set the temp for all the neurons
  N.SetThreshold(netdata.GetThresh());   // Set the thresh for all the neurons

  for(int i = 0; i < Nlayers; i++)
    {
      Lptr = new LAYER(i, &netdata);
      if(i == 0)
        {
          INlayer = OUTlayer = Lptr;
        }
      else
        {
          OUTlayer->SetNext(Lptr);
          OUTlayer = Lptr;
        }
    }

  status = SetWeights();               // Setup connection strengths
  if(status > 0)                       // If > 0 then a Weight linked list 
    return 2;                          //       out-of-bounds occured 

  Alive = 1;                           // The network is in working condition
  return 0;                            // Return 0 on successful operation
}

int NETWORK::SetWeights(void)
{
  LAYER *L1ptr = INlayer,              // Pointer to the input layer
        *L2ptr = INlayer->GetNext();   // pointer to the second layer

  int status = 0;

  while(L2ptr)                        // Start at the hidden layer and traverse
    {
      status = L2ptr->SetWeights(L1ptr->GetFirstNeuron(), &netdata); 
      L1ptr = L1ptr->GetNext();       // Used to mark the current layer
      L2ptr = L2ptr->GetNext();       // Get the next layer in the layer list
    }
  return status;
}


void NETWORK::ApplyVector(unsigned char *InVecPtr, int size)
{
   LAYER *Lptr = INlayer;                 // Start at the 1st layer
   NEURON *Nptr = Lptr->GetFirstNeuron(); // Start at 1st neuron in 1st layer
   double value;                          // Holds pixel value (on/off)
   unsigned char mask;                    // Holds the mask value
                 
  while(Nptr && ( !Nptr->IsBias() ) ) // traverse the list or neurons applying
    {                                 //  the inputs  (But not to bias neuron)
      for(int i = 0; i < size; i++) 
        {
          mask = 0x80;                    
          for(int j = 0; j < 8; j++)      // Cycle thru bit positions
            {                                
              if((InVecPtr[i] & mask) != 0)  
                value = NEURONHIGH;       
              else
                value = NEURONLOW;      
              Nptr->SetOut(value);    // Set output of current neuron to value
              Nptr = Nptr->GetNext(); // Get  next neuron in the input layer
              mask = mask >> 1;                    
            }
        }
    }

/*  Nptr = Lptr->GetFirstNeuron();

  while(Nptr)
    {
      for(int i = 0; i < size; i = i + 2)
        {
          printf("\n");
          for(int j = 0; j < 8; j++)
            {
              if(Nptr->GetOut() >= NEURONHIGH)
                 printf("X");
               else
                 printf(".");
               Nptr = Nptr->GetNext();
            }
        }
    }
*/
} 

void NETWORK::RunNetwork()
{
  LAYER *Lptr = INlayer->GetNext(); // Traverse layers starting w/ 1st hidden
  int out_layer = 0;           // Use to indicate that you are on output layer

  while(Lptr)                  //          and ending with the output layer
    {
      if(Lptr->GetNext() == NULL)   // If NULL, then end of output layer so
        out_layer = 1;              //    build sorted list of output values
      // Ask layer to calculate its values
      Lptr->calc(out_layer); 
      Lptr = Lptr->GetNext();          // Move on to next layer
    }
}


int NETWORK::RequestNthOutNeuron(int neuron_num, NETRESULTS *results)
{
  if(Alive == 0)                              // If Alive = 0 then 
    return 2;                                 //    declare failure

  NEURON *Nptr = OUTlayer->GetFirstNeuron();  // Start at 1st neuron in out lyr

  while(Nptr)                                 // Traverse the list of neurons
    {
      if(neuron_num == Nptr->GetId())          
        {                                      
          results->index     = neuron_num;     
          results->value     = Nptr->GetOut(); 
          results->character = '1';
          return 0;
        }
      Nptr = Nptr->GetNext();   
    }
//  printf("\nOUT OF BOUNDS ERROR on link-list traversal."); 
  return 1;                                                  
}


double NETWORK::RequestTemp(void)
{
  if(Alive == 0)             // If Alive = 0 then no network data is avail and
    return -1.0;             //    network is not in working condition
  else
    return netdata.GetTemp();  // Return the networks temperature value
}

double NETWORK::RequestThresh(void)
{
  if(Alive == 0)
    return -1.0;                                 
  else
    return netdata.GetThresh();  // Return the networks threshold value
}

int NETWORK::RequestLayerSize(int layer_num)
{
  if(Alive == 0)                         
    return 0;                            
  else if(layer_num >= MAXLAYERS)        // If layer_num is an invalid 
    return 0;                            //   layer number then return 0
  else
    return netdata.GetLayerSize(layer_num); // return # of neurons in 
}                                           //    layer number layer_num

//----------------------------------------------------------------------------
//  CLASS RecoList
//----------------------------------------------------------------------------

struct RecoDat {
double  Val;
int     NetID;
char    digit;
RecoDat *next;
};

class RecoList {
private:
  RecoDat       *head;
public:
  RecoList(){head = (RecoDat *)NULL;}
  void kill();                          //delete entire list
  void AddSorted(double, int);          //Add value + net id tp list
  RecoDat QueryNth(int);                //Get nth element in sorted list
  ~RecoList();                          //destructor
};


void RecoList::kill() {                 //delete entire list
RecoDat *p1;
RecoDat *p2;

p1=head;
while (p1) {
   p2=p1;
   delete p1;
   p1=p2->next;
   } /* endwhile */
head = (RecoDat *)NULL;
}


void RecoList::AddSorted(double V, int id) {    //Add value + net id tp list
   RecoDat *Itm;
   RecoDat *cur;
   RecoDat *prev;
   int got1;

Itm = new RecoDat;
Itm->Val=V;
Itm->NetID=id;
Itm->next=(RecoDat *)NULL;
Itm->digit=id+0x30;
if (head) {
   if (V > head->Val) {
      Itm->next=head;     // add as 1st item on list
      head = Itm;
      } 
    else {
      cur=head->next;
      prev=head;
      got1 =0;
      while (cur && !got1) {
         // if we find 1 here its in the middle
         if (V > cur->Val) {
            got1=1;      // found the spot...Add BEFORE cur
            prev->next=Itm;
            Itm->next=cur;
            } 
          else {
            prev=cur;
            cur=cur->next;
            } /* endif */
         } /* endwhile */
         if (!got1) {
            // add at end using prev
            prev->next=Itm;
            } /* endif */
      } /* endif */
   } 
 else {
   head=Itm;           // add as only item on list
   } /* endif */
}

RecoDat RecoList::QueryNth(int n) {           //Get nth element in sorted list
   RecoDat *cur;
   RecoDat rv;
   int found,cnt;

rv.Val=0;
rv.NetID=-1;
rv.digit='*';
cur=head;
found =0;
cnt=0;
while (cur && !found) {
   if (n==cnt) {
      found=1;
      rv.Val=   cur->Val;
      rv.NetID= cur->NetID;
      rv.digit= cur->digit;
      } 
   else {
      cnt++;
      cur=cur->next;
      } /* endif */
   } /* endwhile */
return rv;
}

RecoList::~RecoList() {                         //destructor
kill();
}

//----------------------------------------------------------------------------
// class RECOSYS
//----------------------------------------------------------------------------

class RECOSYS
{
private:
  NETWORK       *net;
  RecoList      rList;

public:
  RECOSYS(void) ;
  int    Setup(char *);                    // parm is filename of file with
                                           // weight filenames for all networks
  void   ApplyVector(unsigned char *, int);    // same vect for -> all nets
  void   RunReco(void);                        // run all nets, sort results
  int    QueryNth(int, NETRESULTS *);          // results from Nth net
  int    QueryNthBest(int, NETRESULTS *);      // results from Nth best net
  double QueryTemp() {return net->RequestTemp();}
  double QueryThresh() {return net->RequestThresh();}
  int    QueryLayerSize(int l){return net->RequestLayerSize(l);}
  int    QueryNetCount() { return 10; }
  int    QueryAlive() { return net->GetAlive(); }

};

RECOSYS::RECOSYS() {
   int i;
   NETWORK *N;
for (i=0; i<10; i++) {   // create 10 generic networks
   N = new NETWORK;
   if (net) {
      N->SetNext(net);     // point to old 1st net
      net=N;
      } 
    else {
      net=N;
      } /* endif */
   } /* endfor */
   //WinAlarm(HWND_DESKTOP,WA_NOTE);
   //WinAlarm(HWND_DESKTOP,WA_ERROR);
}

int RECOSYS::Setup(char *Zname) {
   FILE *WFL;                //weight file list pointer
   char Wname[40];
   int i;
   NETWORK *N;
   int rv=0;
if((WFL = fopen(Zname, "r")) == NULL) return 1;
N=net;                       // set equal to head
for (i=0; i<10; i++) {       //init each of the nets
   fscanf(WFL,"%s",Wname);
   if (N->Setup(Wname)) rv=1;
   N=N->GetNext();
   } /* endfor */
return rv;
}

void RECOSYS::ApplyVector(unsigned char *Vect, int Sz) {  
   int i;
   NETWORK *N;
N=net;                       // set equal to head
for (i=0; i<10; i++) {       // send same vector to each of the nets
   N->ApplyVector(Vect, Sz);
   N=N->GetNext();
   } /* endfor */
}

void RECOSYS::RunReco(void) {                    
   int i;
   NETWORK *N;
   NETRESULTS results;
N=net;                       // set equal to head
for (i=0; i<10; i++) {       // run each of the nets sucsesively
   N->RunNetwork();
   N=N->GetNext();
   } /* endfor */
//BUILD THE SORTED LIST HERE!!!!
//BUT 1st INIT LIST TO EMPTY
rList.kill();
N=net;                       // reset to head
for (i=0; i<10; i++) {
  N->RequestNthOutNeuron( 0, &results);
  rList.AddSorted(results.value, i);
   N=N->GetNext();
   } /* endfor */

}

int RECOSYS::QueryNth(int n, NETRESULTS *rv)   {
   int i;
   NETWORK *Nptr;
   NETRESULTS results;
rv->value    = 0.0;
rv->index    = -1;
rv->character= '*';
if (n>9) return 1;  // out of bounds
Nptr=net;                       // set equal to head
for (i=0; i<n; i++) {
   Nptr=Nptr->GetNext();
   } /* endfor */
if (!Nptr->RequestNthOutNeuron(0, &results)) {
   rv->value    = results.value;
   rv->index    = n;
   rv->character= n+0x30;
   return 0;
   }
return 2;  // Nth net not found
}

int RECOSYS::QueryNthBest(int n, NETRESULTS *rv)  {
   RecoDat RD=rList.QueryNth(n);
   rv->value = RD.Val;
   rv->index = RD.NetID;
   rv->character = RD.digit;
return 0;
}
