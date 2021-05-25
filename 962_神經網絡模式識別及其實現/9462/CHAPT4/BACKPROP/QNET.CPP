
// DEFINES

#define NEURONHIGH   1.0               // Neuron's high output value
#define NEURONLOW    0.0               // Neuron's low output value

#define MAXLAYERS    4         // MAX NUMBER OF LAYERS IN NET (IN OUT & HIDDEN)
#define MAXNEURONS 120         // MAX NUMBER OF NEURONS PER LAYER
#define MAXPATTERNS 80         // MAX NUMBER OF PATTERNS IN A TRAINING SET
#define SIGMOID      0         // Choose Squashing fn
#define STEPFN       1         // Choose Squashing fn
#define TRUE         1
#define FALSE        0


struct NETRESULTS
{
  int           index;                      // Neurons identification number
  double        value;                      // Neurons output value
  char          character;                  // char representation of digit
};



// Pattern data
int NumPatterns;                            // Total patterns in training set
double InPattern[MAXPATTERNS][MAXNEURONS];  // Input values for each pattern
double Desired[MAXPATTERNS][MAXNEURONS];    // desired value for each
                                            //   pattern/output


class NETWORK {
private:
  int           Alive;

  double W[MAXLAYERS][MAXNEURONS][MAXNEURONS];  // WEIGHTS MATRIX
  double Neuron[MAXLAYERS][MAXNEURONS];
  // Topology
  int    NumLayers;              // Number of layers
  int    OutLayerIndx;           // array index of last layer
  int    LayerSize[MAXLAYERS];   // Number of neurons in the each layer
  int    SelcActFn;              // Activation fn selector
  double Temperature;            // For sigmoid
  double threshold;              // Neurons firing threshold

  NETWORK       *next;                  // Need more than 1 network ... OK

public:
  NETWORK(void) { Alive = 0; next=(NETWORK *)NULL; SelcActFn =SIGMOID;}           
  int    Setup(char *);                           // REPLACES: void GetWeights(); 
  void   ApplyVector(unsigned char *, int);                                     
  void   RunNetwork(void);                        // REPLACES: void RunNet();   
  int    RequestNthOutNeuron(int, NETRESULTS *);                               
  double RequestTemp(void);  
  double RequestThresh(void);   
  int    RequestLayerSize(int); 
  int    GetAlive() { return Alive; }  
  NETWORK *GetNext() {return next;}    
  void    SetNext(NETWORK *netptr) {next=netptr;} 

  // The following methods are for test (ie they are not used by GRID1)
  void LoadTestSet(char *Fname) ;                 
  void Get1Pat(int p);                            
  void ShowResults(char *Fname);                  
  void   SaveWeights(char *WgtName);              
  double gimme(int l,int n){return Neuron[l][n];} 
private:
 
  double ActivationFn(double Net, double Tempr);  
  double Sigmoid(double Net, double Tempr){ return 1.0/(1.0 + exp(-Net/Tempr)); } 
  double StepFn(double Net);                                                      

};


void   NETWORK::SaveWeights(char *WgtName) {
int lyr,s,d;
double zWT;
FILE *WEIGHTFILE;

   WEIGHTFILE = fopen(WgtName,"w");
   if (WEIGHTFILE==NULL){
      printf("Unable to open weight file for output:%s\n",WgtName);
      exit(0);
      }
   printf("SAVING CALCULATED WEIGHTS:\n\n");
   fprintf(WEIGHTFILE,"0.00\n");                  // Threshold always 0
   fprintf(WEIGHTFILE,"%lf\n",Temperature);       // Temperature
   fprintf(WEIGHTFILE,"%d\n",NumLayers);         // Number of layers
   for (lyr=0; lyr<NumLayers; lyr++) {            // Save topology
      fprintf(WEIGHTFILE,"%d\n",LayerSize[lyr]); // Number of neurons/layer
      }
   for (lyr=1; lyr<NumLayers; lyr++) {         // Start at 1st hidden
      for (d=0; d<LayerSize[lyr]; d++) {
         for (s=0; s<=LayerSize[lyr-1]; s++) { // One extra for bias 
            zWT=W[lyr][s][d];
            fprintf(WEIGHTFILE,"%.25lf\n",zWT);
            //printf("W(%d,%d,%d)=%lf ",lyr,s,d,W[lyr][s][d]);
            }
         }
      }
   fclose(WEIGHTFILE);
}
                                  
double NETWORK::RequestTemp(void) {
  if(Alive == 0)             // If Alive = 0 then no network data is avail and
    return -1.0;             //    network is not in working condition
  else
    return Temperature;      // Return the networks temperature value
}


double NETWORK::RequestThresh(void) {
  if(Alive == 0)
    return -1.0;                                 
  else
    return threshold;            // Return the networks threshold value
}

int NETWORK::RequestLayerSize(int layer_num) {
  if(Alive == 0)                         
    return 0;                            
  else if(layer_num >= MAXLAYERS)        // If layer_num is an invalid 
    return 0;                            //   layer number then return 0
  else
    return LayerSize[layer_num];         // return # of neurons in
}                                        //    layer number layer_num


int NETWORK::RequestNthOutNeuron(int neuron_num, NETRESULTS *results)
{
if(Alive == 0)                              // If Alive = 0 then 
  return 2;                                 //    declare failure
if (neuron_num>LayerSize[OutLayerIndx])
   return 1;
results->index     = neuron_num;     
results->value     = Neuron[OutLayerIndx][neuron_num];
results->character = '1';
return 0;
}


void NETWORK::ApplyVector(unsigned char *InVecPtr, int size) {
   int n,i,j;
   double value;                          // Holds pixel value (on/off)
   unsigned char mask;                    // Holds the mask value
                 
n=0;
for(i = 0; i < size; i++) {
    mask = 0x80;                    
    for(j = 0; j < 8; j++) {    // Cycle thru bit positions
        if((InVecPtr[i] & mask) != 0)  
          value = NEURONHIGH;       
        else
          value = NEURONLOW;      
        Neuron[0][n]=value;     // Show it to the neuron
        n++;
        mask = mask >> 1;                    
        }
    }
} 


double NETWORK::ActivationFn(double Net, double Tempr){
   double rv;
   switch (SelcActFn) {
      case SIGMOID:
         rv= Sigmoid(Net, Tempr);
         break;
      case STEPFN:
         rv= StepFn(Net);
         break;
      default:rv=-1.0;
      } /* endswitch */
   return rv;
}


double NETWORK::StepFn(double Net){
if (Net>0.0) {
   return 1;
   }
 else {
   return 0;
   }
}



void NETWORK::RunNetwork(){
   int lyr;     // layer to calculate
   int dNeuron; // dest layer neuron
   int sNeuron; // src layer neuron
   double SumNet;
   double out;

for (lyr=1; lyr<NumLayers; lyr++) {
   Neuron[lyr-1][LayerSize[lyr-1]]=1.0; //force bias neuron output to 1.0
   for (dNeuron=0; dNeuron<LayerSize[lyr]; dNeuron++) {
      SumNet=0.0;
      for (sNeuron=0; sNeuron <= LayerSize[lyr-1]; sNeuron++) {  //add 1 for bias
         SumNet += Neuron[lyr-1][sNeuron] * W[lyr][sNeuron][dNeuron];
         }
      out=ActivationFn(SumNet,Temperature);
      Neuron[lyr][dNeuron] = out;
      }
   }
}



int NETWORK::Setup(char *wgt_file_name) {
   FILE   *WTFILE;                           // Pointer to a weight file
   double zWT;                               // Used to hold a temporary weight
   int lyr,s,d;

if((WTFILE = fopen(wgt_file_name, "r")) == NULL)
  return 1;

fscanf(WTFILE, "%lg", &threshold);     // Read in threshold value
fscanf(WTFILE, "%lg", &Temperature);   // Read in temperature value
fscanf(WTFILE, "%d",  &NumLayers);     // Read in # of layers
OutLayerIndx = NumLayers-1;         // accomodate 0 org'd arrays

for(int a = 0; a < MAXLAYERS; a++)
  LayerSize[a] = 0;                             // Initialize array to zero

for(int b = 0; b < NumLayers; b++)
  fscanf(WTFILE, "%d", &LayerSize[b]);          // Read # neurons in each layer

   for (lyr=1; lyr<NumLayers; lyr++) {         // Start at 1st hidden
      for (d=0; d<LayerSize[lyr]; d++) {
         for (s=0; s<=LayerSize[lyr-1]; s++) { // One extra for bias 
            fscanf(WTFILE,"%lf",&zWT);          // read weights from file
            W[lyr][s][d] =zWT;
            }
         }
      }
fclose(WTFILE);                        // Close the weight file
Alive = 1;                           // The network is in working condition
return 0;
}


void NETWORK::LoadTestSet(char *Fname) {
FILE *PFILE;
int PGindx;
int x,mask;
int pat,i,j;
double inVal;
int NumPatBytes;   

PFILE = fopen(Fname,"r");    // batch
if (PFILE==NULL){
   printf("\nUnable to open file \n");
   exit(0);
   }
fscanf(PFILE,"%d",&NumPatterns);
NumPatBytes= LayerSize[0] / 8; // # of Input lyr neurons must be divisible by 8

for (pat=0; pat<NumPatterns; pat++) {
   PGindx=0;
   for (i=0; i<NumPatBytes; i++) {
      fscanf(PFILE,"%x",&x);
      mask = 0x80;
      for (j=0; j<8; j++) {
         if ((mask & x) > 0) {
            InPattern[pat][PGindx]=1.0;
            }
          else {
            InPattern[pat][PGindx]=0.0;
            } /* endif */
         mask=mask/2; 
         PGindx++;
         } /* endfor */
      } /* endfor */
   // Now get desired / expected values
   for (i=0; i<LayerSize[OutLayerIndx]; i++) {
      fscanf(PFILE,"%lf",&inVal);
      Desired[pat][i]=inVal;
      } /* endfor */
   } /* endfor */
fclose(PFILE);
}


void NETWORK::Get1Pat(int p){
int i;
for (i=0; i<LayerSize[0]; i++) {
    Neuron[0][i]=InPattern[p][i];   // Show it to the neurons
    }
}


void NETWORK::ShowResults(char *Fname){
   double x;
   double y;
   int    j,p;
   FILE *RSLTS;
RSLTS = fopen(Fname,"w");
for (p=0; p<NumPatterns; p++) {
   Get1Pat(p);
   RunNetwork();
   for (j=0;j<LayerSize[OutLayerIndx] ;j++) {
      x= Neuron[OutLayerIndx][j];
      y= fabs(Desired[p][j]-x);
      printf("pattern %d  Out=%lf Err=%lf\n", p, x, y);
      if (RSLTS!=NULL) {
      fprintf(RSLTS,"pattern %d  Out=%lf Err=%lf\n", p, x, y);
         } /* endif */
      }
   }
}


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