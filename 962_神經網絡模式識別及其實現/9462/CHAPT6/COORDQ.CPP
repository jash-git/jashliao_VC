
//-------------------------------------------------------------------------------------
class coordqel {
private:
  tgrid    coord;
  coordqel *next;
public:
  coordqel(){next=NULL;}
  void setnext(coordqel *p){next=p;}
  void setxy(int x,int y){coord.x=x; coord.y=y;}
  void query(int& x, int& y){x=coord.x; y=coord.y;}
  coordqel *querynext(){return next;}
};

//-------------------------------------------------------------------------------------
class coordq {
private:
  coordqel *head;
  int      count;
public:
  coordq(){head=NULL;}
  void enQTop(int x, int y);
  void enQTop(tgrid pel){enQTop(pel.x, pel.y);}
  int  deQTop(int& x, int& y);
  int  Qdelete(coordqel *p);
  int  find(int x, int y);
  int  DatAvail();
  coordqel  *pfind(int x, int y);
  void dump();
};


void  coordq::dump(){
   coordqel *tmp;
   int i,x,y;
i=0;
tmp=head;
while (tmp) {
   tmp->query(x,y);
   printf("Entry:%d=[%d,%d]\n",i,x,y);
   i++;
   tmp=tmp->querynext();
   } /* endwhile */
printf("There are %d elements on queue\n\n",i);
}

int  coordq::DatAvail(){
if (head==NULL)
   return 0;
  else
   return 1;
}

int  coordq::find(int x, int y){
   int x1,y1;
   coordqel *tmp;
tmp=head;
while (tmp!=NULL) {
  tmp->query(x1,y1);
  if ((x==x1) && (y==y1)) 
     return 1;
   else 
     tmp=tmp->querynext();
  } /* endwhile */
return 0;
}

coordqel  *coordq::pfind(int x, int y){
   int x1,y1;
   coordqel *tmp;
tmp=head;
while (tmp!=NULL) {
  tmp->query(x1,y1);
  if ((x==x1) && (y==y1)) 
     return tmp;
   else 
     tmp=tmp->querynext();
  } /* endwhile */
return NULL;
}

int coordq::Qdelete(coordqel *p){
   coordqel *cur;
   coordqel *prev;
   cur=head; prev=NULL;
   while ((cur!=NULL) && (cur!=p)) {
      prev=cur;
      cur=cur->querynext();
      } /* endwhile */
   if (cur!=NULL) {
      if(prev!=NULL)
         prev->setnext(cur->querynext());
       else
         head=cur->querynext();
      delete cur;
      return 1;
      } 
    else {
      return 0;      // bad pointer, Q empty or just not found. delete failed.
      } /* endif */
}

void coordq::enQTop(int x, int y){
   coordqel *tmp;
   tmp=new coordqel;
   tmp->setxy(x,y);
   tmp->setnext(head);
   head=tmp;
}

int  coordq::deQTop(int& x, int& y){
   coordqel *tmp;
   if(head!=NULL) {
      head->query(x,y);
      tmp=head;
      head=head->querynext();
      delete tmp;
      return 1;
      }
    else {
      return 0;
      }
}


