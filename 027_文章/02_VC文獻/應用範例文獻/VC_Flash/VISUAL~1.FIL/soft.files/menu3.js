document.writeln("<link href=\"http://soft.yesky.com/imagesnew/software/iframe/navigation/menu3.css\" rel=\"stylesheet\">");


function menuOver(obj1,obj2)
{
  obj1.className='menu_over_bg';
  obj2.style.visibility='visible';
}
function menuOut(obj1,obj2)
{
  obj1.className='menu_bg';
  obj2.style.visibility='hidden';
}
function cMenuOver(obj1,obj2)
{
  obj1.className='c_menu_over';
  obj2.style.visibility='visible';
}
function cMenuOut(obj1,obj2)
{
  obj1.className='c_menu';
  obj2.style.visibility='hidden';
}

var menus_num=8;
var menu_width=90;
var menus=new Array()
var menus_link=new Array();
for(i=0;i<menus_num;i++)
{
  menus[i]=new Array();
  menus_link[i]=new Array();
}

//--- ���˵�һ ----

menus[0]['main']="������ߡ�";                //��Ŀ����
menus[0]['width']=90;
menus_link[0]['url']="http://soft.yesky.com/SoftChannel/72351163642544128/index.shtml";

   menus[0][0]=new Array();                 //�Ӳ˵�1 ע��menus[0][0]���±�仯
   menus[0][0]['main']="��ҳ�հ�";
   menus[0][0]['width']=90;
   menus_link[0][0]=new Array();
   menus_link[0][0]['url']="http://soft.yesky.com/SoftChannel/72351167937511424/index.shtml";

      menus[0][0][0]="��ҳ����";          //Ҷ�Ӳ˵�
      menus_link[0][0][0]="http://soft.yesky.com/SoftChannel/72351168004620288/index.shtml";
      menus[0][0][1]="Dreamweaver";          //Ҷ�Ӳ˵�
      menus_link[0][0][1]="http://soft.yesky.com/SoftChannel/72351168004685824/index.shtml";
      menus[0][0][2]="FrontPage";
      menus_link[0][0][2]="http://soft.yesky.com/SoftChannel/72351168004816896/index.shtml";
      menus[0][0][3]="Fireworks";
      menus_link[0][0][3]="http://soft.yesky.com/SoftChannel/72351168005013504/index.shtml";
      menus[0][0][4]="GOLIVE";
      menus_link[0][0][4]="http://soft.yesky.com/SoftChannel/72351168004882432/index.shtml";
      menus[0][0][5]="��������";
      menus_link[0][0][5]="http://soft.yesky.com/SoftChannel/72351168004947968/index.shtml";
      menus[0][0][6]="�������";
      menus_link[0][0][6]="http://soft.yesky.com/SoftChannel/72351168038174720/index.shtml";
   //------

   menus[0][1]=new Array();                   //�Ӳ˵�2  ע��menus[0][1]���±�仯
   menus[0][1]['main']="��ҳ����";
   menus[0][1]['width']=90;
   menus_link[0][1]=new Array();
   menus_link[0][1]['url']="http://soft.yesky.com/SoftChannel/72351167954288640/index.shtml";

      menus[0][1][0]="CSS";
      menus_link[0][1][0]="http://soft.yesky.com/SoftChannel/72351167954354176/index.shtml";

      menus[0][1][1]="HTML";
      menus_link[0][1][1]="http://soft.yesky.com/SoftChannel/72351167954485248/index.shtml";

      menus[0][1][2]="JavaScript";
      menus_link[0][1][2]="http://soft.yesky.com/SoftChannel/72351167954419712/index.shtml";
      menus[0][1][3]="��������";
      menus_link[0][1][3]="http://soft.yesky.com/SoftChannel/72351167954616320/index.shtml";
      menus[0][1][4]="XML";
      menus_link[0][1][4]="http://soft.yesky.com/SoftChannel/72351167954747392/index.shtml";
      menus[0][1][5]="���ɵ��";
      menus_link[0][1][5]="http://soft.yesky.com/SoftChannel/72351167954550784/index.shtml";
      menus[0][1][6]="��������";
      menus_link[0][1][6]="http://soft.yesky.com/SoftChannel/72351167954812928/index.shtml";
   //---
   menus[0][2]=new Array();                   //�Ӳ˵�3  ��������
   menus[0][2]['main']="��������";
   menus[0][2]['width']=90;
   menus_link[0][2]=new Array();
   menus_link[0][2]['url']="http://soft.yesky.com/SoftChannel/72351172232478720/index.shtml";

      menus[0][2][0]="ƽ�����";
      menus_link[0][2][0]="http://soft.yesky.com/SoftChannel/72351172282810368/index.shtml";
      menus[0][2][1]="Photoshop";
      menus_link[0][2][1]="http://soft.yesky.com/SoftChannel/72351172283006976/index.shtml";
      menus[0][2][2]="ImageReady";
      menus_link[0][2][2]="http://soft.yesky.com/SoftChannel/72351172282941440/index.shtml";
      menus[0][2][3]="CorelDraw";
      menus_link[0][2][3]="http://soft.yesky.com/SoftChannel/72351172283072512/index.shtml";
      menus[0][2][4]="Illustrator";
      menus_link[0][2][4]="http://soft.yesky.com/SoftChannel/72351172283138048/index.shtml";
      menus[0][2][5]="Freehand";
      menus_link[0][2][5]="http://soft.yesky.com/SoftChannel/72351172283334656/index.shtml";
      menus[0][2][6]="SVG";
      menus_link[0][2][6]="http://soft.yesky.com/SoftChannel/72351172283203584/index.shtml";
      menus[0][2][7]="Painter";
      menus_link[0][2][7]="http://soft.yesky.com/SoftChannel/72351172283400192/index.shtml";
      menus[0][2][8]="����";
      menus_link[0][2][8]="http://soft.yesky.com/SoftChannel/72351172283269120/index.shtml";
      menus[0][2][9]="3DS Max";
      menus_link[0][2][9]="http://soft.yesky.com/SoftChannel/72351172266098688/index.shtml";
      menus[0][2][10]="AutoCAD";
      menus_link[0][2][10]="http://soft.yesky.com/SoftChannel/72351172266164224/index.shtml";
      menus[0][2][11]="����֪ʶ";
      menus_link[0][2][11]="http://soft.yesky.com/SoftChannel/72351172249255936/index.shtml";

   //--- Flash---
   menus[0][3]=new Array();                   //�Ӳ˵�4 
   menus[0][3]['main']="Flash";
   menus[0][3]['width']=90;
   menus_link[0][3]=new Array();
   menus_link[0][3]['url']="http://soft.yesky.com/SoftChannel/72351185117380608/index.shtml";

      menus[0][3][0]="�����̳�";
      menus_link[0][3][0]="http://soft.yesky.com/SoftChannel/72351185134157824/index.shtml";
      menus[0][3][1]="��������";
      menus_link[0][3][1]="http://soft.yesky.com/SoftChannel/72351185150935040/index.shtml";
      menus[0][3][2]="ʵ������";
      menus_link[0][3][2]="http://soft.yesky.com/SoftChannel/72351185184489472/index.shtml";
      menus[0][3][3]="�ܱ߸���";
      menus_link[0][3][3]="http://soft.yesky.com/SoftChannel/72351185201266688/index.shtml";
      menus[0][3][4]="��������";
      menus_link[0][3][4]="http://soft.yesky.com/SoftChannel/72351185167712256/index.shtml";

//������ý��

   menus[0][4]=new Array();                   //�Ӳ˵�4 
   menus[0][4]['main']="��ý��";
   menus[0][4]['width']=90;
   menus_link[0][4]=new Array();
   menus_link[0][4]['url']="http://soft.yesky.com/SoftChannel/72351180822413312/index.shtml";

      menus[0][4][0]="Authorware";
      menus_link[0][4][0]="http://soft.yesky.com/SoftChannel/72351180839190528/index.shtml";
      menus[0][4][1]="Director";
      menus_link[0][4][1]="http://soft.yesky.com/SoftChannel/72351180855967744/index.shtml";
      menus[0][4][2]="��Ƶ����";
      menus_link[0][4][2]="http://soft.yesky.com/SoftChannel/72351180872744960/index.shtml";
      menus[0][4][3]="����";
      menus_link[0][4][3]="http://soft.yesky.com/SoftChannel/72351180889522176/index.shtml";


   menus[0][5]="��Ʒ����";
   menus_link[0][5]="http://soft.yesky.com/SoftChannel/72351176527446016/index.shtml";

   menus[0][6]="ͼ��ר��";
   menus_link[0][6]="http://soft.yesky.com/SoftChannel/72348986094125056/index.shtml";

   menus[0][7]="��ҳר��";
   menus_link[0][7]="http://soft.yesky.com/SoftChannel/72348990389092352/index.shtml";



//--- ���˵��� ʵ�������ѯ----

menus[1]['main']="���������";                
menus[1]['width']=100;
menus_link[1]['url']="http://soft.yesky.com/SoftChannel/72347865107660800/index.shtml";

   menus[1][0]=new Array();                 
   menus[1][0]['main']="ϵͳ����";
   menus[1][0]['width']=90;
   menus_link[1][0]=new Array();
   menus_link[1][0]['url']="http://soft.yesky.com/SoftChannel/72347869402628096/index.shtml";

      menus[1][0][0]="ϵͳ�Ż�";          
      menus_link[1][0][0]="http://soft.yesky.com/SoftChannel/72347869419405312/index.shtml";

      menus[1][0][1]="Ӳ�����";
      menus_link[1][0][1]="http://soft.yesky.com/SoftChannel/72347869469736960/index.shtml";

   menus[1][1]=new Array();                   
   menus[1][1]['main']="���繤��";
   menus[1][1]['width']=90;
   menus_link[1][1]=new Array();
   menus_link[1][1]['url']="http://soft.yesky.com/SoftChannel/72347873697595392/index.shtml";

      menus[1][1][0]="�������";
      menus_link[1][1][0]="http://soft.yesky.com/SoftChannel/72347873714372608/index.shtml";
      menus[1][1][1]="���罻��";
      menus_link[1][1][1]="http://soft.yesky.com/SoftChannel/72347873764704256/index.shtml";
      menus[1][1][2]="���繹��";
      menus_link[1][1][2]="http://soft.yesky.com/SoftChannel/72347873781481472/index.shtml";
	  menus[1][1][3]="�ʼ�����";
      menus_link[1][1][3]="http://soft.yesky.com/SoftChannel/72347873798258688/index.shtml";
      menus[1][1][4]="���繤��";
      menus_link[1][1][4]="http://soft.yesky.com/SoftChannel/72347873815035904/index.shtml";

   menus[1][2]=new Array();                   
   menus[1][2]['main']="ý�岥��";
   menus[1][2]['width']=90;
   menus_link[1][2]=new Array();
   menus_link[1][2]['url']="http://soft.yesky.com/SoftChannel/72346765596033024/index.shtml";

      menus[1][2][0]="��ý��";
      menus_link[1][2][0]="http://soft.yesky.com/SoftChannel/72346769891000320/index.shtml";
      menus[1][2][1]="����������";
      menus_link[1][2][1]="http://soft.yesky.com/SoftChannel/72346774185967616/index.shtml";
      menus[1][2][2]="��Ƶ����";
      menus_link[1][2][2]="http://soft.yesky.com/SoftChannel/72346778480934912/index.shtml";
      menus[1][2][3]="��Ƶ����";
      menus_link[1][2][3]="http://soft.yesky.com/SoftChannel/72346782775902208/index.shtml";


   menus[1][3]=new Array();                   
   menus[1][3]['main']="ר�����";
   menus[1][3]['width']=90;
   menus_link[1][3]=new Array();
   menus_link[1][3]['url']="http://soft.yesky.com/SoftChannel/72347899467399168/index.shtml";

      menus[1][3][0]="�������";
      menus_link[1][3][0]="http://soft.yesky.com/SoftChannel/72347899500953600/index.shtml";
      menus[1][3][1]="�������";
      menus_link[1][3][1]="http://soft.yesky.com/SoftChannel/72347899517730816/index.shtml";
      menus[1][3][2]="�������";
      menus_link[1][3][2]="http://soft.yesky.com/SoftChannel/72347899484176384/index.shtml";
      menus[1][3][3]="���ɹ���";
      menus_link[1][3][3]="http://soft.yesky.com/SoftChannel/72347899534508032/index.shtml";


   menus[1][4]=new Array();                   
   menus[1][4]['main']="�������";
   menus[1][4]['width']=90;
   menus_link[1][4]=new Array();
   menus_link[1][4]['url']="http://soft.yesky.com/SoftChannel/72347903762366464/index.shtml";
      menus[1][4][0]="��Ϸ���";
      menus_link[1][4][0]="http://soft.yesky.com/SoftChannel/72347903795920896/index.shtml";
      menus[1][4][1]="����Ȥζ";
      menus_link[1][4][1]="http://soft.yesky.com/SoftChannel/72347903779143680/index.shtml";


   menus[1][5]="���̹���";
   menus_link[1][5]="http://soft.yesky.com/SoftChannel/72347877992562688/index.shtml";
   menus[1][6]="���̹���";
   menus_link[1][6]="http://soft.yesky.com/SoftChannel/72347908057333760/index.shtml";
   menus[1][7]="ͼ�񹤾�";
   menus_link[1][7]="http://soft.yesky.com/SoftChannel/72347882287529984/index.shtml";
   menus[1][8]="�ļ�����";
   menus_link[1][8]="http://soft.yesky.com/SoftChannel/72347886582497280/index.shtml";
   menus[1][9]="��ȫ����";
   menus_link[1][9]="http://soft.yesky.com/SoftChannel/72347895172431872/index.shtml";
   menus[1][10]="��������";
   menus_link[1][10]="http://soft.yesky.com/SoftChannel/72347890877464576/index.shtml";

// ----���˵��� ����������

menus[2]['main']="���򿪷���";                
menus[2]['width']=90;
menus_link[2]['url']="http://soft.yesky.com/SoftChannel/72342367549521920/index.shtml";


 menus[2][0]=new Array();    
 menus[2][0]['main']="��������";
 menus[2][0]['width']=90;
 menus_link[2][0]=new Array();
 menus_link[2][0]['url']="http://soft.yesky.com/SoftChannel/72342371844489216/index.shtml";

  menus[2][0][0]="Java";
  menus_link[2][0][0]="http://soft.yesky.com/SoftChannel/72342371961929728/index.shtml";

  menus[2][0][1]="����ר��";
  menus_link[2][0][1]="http://soft.yesky.com/SoftChannel/72342371928375296/index.shtml";

  menus[2][0][2]="�������ű����";
  menus_link[2][0][2]="http://soft.yesky.com/SoftChannel/72342371945152512/index.shtml";

  menus[2][0][3]="Ƕ��ʽ����";
  menus_link[2][0][3]="http://soft.yesky.com/SoftChannel/72342371878043648/index.shtml";

  menus[2][0][4]="ϵͳ���";
  menus_link[2][0][4]="http://soft.yesky.com/SoftChannel/72342371911598080/index.shtml";

  menus[2][0][5]="������·";
  menus_link[2][0][5]="http://soft.yesky.com/SoftChannel/72342371861266432/index.shtml";

 menus[2][1]=new Array();                   
 menus[2][1]['main']="΢����";
 menus[2][1]['width']=90;
 menus_link[2][1]=new Array();
 menus_link[2][1]['url']="http://soft.yesky.com/SoftChannel/72342380434423808/index.shtml"; 

  menus[2][1][0]="ASP.NET";
  menus_link[2][1][0]="http://soft.yesky.com/SoftChannel/72342371945218048/index.shtml";

  menus[2][1][1]="C#";
  menus_link[2][1][1]="http://soft.yesky.com/SoftChannel/72342380468109312/index.shtml";

  menus[2][1][2]="VC.NET";
  menus_link[2][1][2]="http://soft.yesky.com/SoftChannel/72342371928702976/index.shtml";

  menus[2][1][3]="VB.NET";
  menus_link[2][1][3]="http://soft.yesky.com/SoftChannel/72342371928637440/index.shtml";

  menus[2][1][4]="XML";
  menus_link[2][1][4]="http://soft.yesky.com/SoftChannel/72342376223342592/index.shtml";

  menus[2][1][5]="WEBService";
  menus_link[2][1][5]="http://soft.yesky.com/SoftChannel/72342380468371456/index.shtml";

  menus[2][1][6]="����ר��";
  menus_link[2][1][6]="http://soft.yesky.com/SoftChannel/72342380484755456/index.shtml";

  menus[2][1][7]="��̬����";
  menus_link[2][1][7]="http://soft.yesky.com/SoftChannel/72342380451201024/index.shtml";

 menus[2][2]=new Array();               
 menus[2][2]['main']="����׷��";
 menus[2][2]['width']=90;
 menus_link[2][2]=new Array();
 menus_link[2][2]['url']="http://soft.yesky.com/SoftChannel/72342376139456512/index.shtml";

  menus[2][2][0]="XML��.Net";
  menus_link[2][2][0]="http://soft.yesky.com/SoftChannel/72342376223342592/index.shtml";

  menus[2][2][1]="��������";
  menus_link[2][2][1]="http://soft.yesky.com/SoftChannel/72342376173010944/index.shtml";
 
  menus[2][2][2]="ϵͳ����";
  menus_link[2][2][2]="http://soft.yesky.com/SoftChannel/72342376189788160/index.shtml";

  menus[2][2][3]="�¼���Ӧ��";
  menus_link[2][2][3]="http://soft.yesky.com/SoftChannel/72342376156233728/index.shtml";

 menus[2][3]=new Array();               
 menus[2][3]['main']="�������";
 menus[2][3]['width']=90;
 menus_link[2][3]=new Array();
 menus_link[2][3]['url']="http://soft.yesky.com/SoftChannel/72342393319325696/index.shtml";

  menus[2][3][0]="���󹤳�";
  menus_link[2][3][0]="http://soft.yesky.com/SoftChannel/72342393336102912/index.shtml";
  menus[2][3][1]="��Ŀ����";
  menus_link[2][3][1]="http://soft.yesky.com/SoftChannel/72342393352880128/index.shtml";
  menus[2][3][2]="�������";
  menus_link[2][3][2]="http://soft.yesky.com/SoftChannel/72342393369657344/index.shtml";
  menus[2][3][3]="����ĵ�";
  menus_link[2][3][3]="http://soft.yesky.com/SoftChannel/72342393386434560/index.shtml";

 menus[2][4]="��������";
 menus_link[2][4]="http://soft.yesky.com/SoftChannel/72342397614292992/index.shtml";
 menus[2][5]="��������";
 menus_link[2][5]="http://soft.yesky.com/SoftChannel/72342389024358400/index.shtml";


  //----�˵���   ����ϵͳ

menus[3]['main']="����ϵͳ��";
menus[3]['width']=90;
menus_link[3]['url']="http://soft.yesky.com/SoftChannel/72350064130916352/index.shtml";

   menus[3][0]="Windows_XP"                 //�Ӳ˵�1 ע��menus[3][0]���±�仯
   menus_link[3][0]="http://soft.yesky.com/SoftChannel/72350085605752832/index.shtml";

   menus[3][1]="Win2000/NT"                 //�Ӳ˵�1 ע��menus[3][0]���±�仯
   menus_link[3][1]="http://soft.yesky.com/SoftChannel/72350077015818240/index.shtml";
   menus[3][2]="Win9x/Me"                 
   menus_link[3][2]="http://soft.yesky.com/SoftChannel/72350072720850944/index.shtml";
   menus[3][3]="Win2003";          
   menus_link[3][3]="http://soft.yesky.com/SoftChannel/72350094195687424/index.shtml";

   menus[3][4]="Linux����";
   menus_link[3][4]="http://soft.yesky.com/SoftChannel/72350081327562752/index.shtml"; 
   menus[3][5]="Linux����";
   menus_link[3][5]="http://soft.yesky.com/SoftChannel/72350081361117184/index.shtml";
   menus[3][6]="Linuxѧϰ";
   menus_link[3][6]="http://soft.yesky.com/SoftChannel/72350081344339968/index.shtml";
   menus[3][7]="Linux����";
   menus_link[3][7]="http://soft.yesky.com/SoftChannel/72350081394671616/index.shtml";
   menus[3][8]="LinuxӦ��";          
   menus_link[3][8]="http://soft.yesky.com/SoftChannel/72350081377894400/index.shtml";

   menus[3][9]="��������ϵͳ"                 
   menus_link[3][9]="http://soft.yesky.com/SoftChannel/72350068425883648/index.shtml";
   menus[3][10]="ϵͳ����"                 
   menus_link[3][10]="http://soft.yesky.com/SoftChannel/72350089900720128/index.shtml";


//�˵��� �칫���

menus[4]['main']="�칫�����";                //��Ŀ����
menus[4]['width']=90;
menus_link[4]['url']="http://soft.yesky.com/SoftChannel/72357760712310784/index.shtml";

   menus[4][0]=new Array();                 //�Ӳ˵�1 ע��menus[4][0]���±�仯
   menus[4][0]['main']="OFFICE";
   menus[4][0]['width']=90;
   menus_link[4][0]=new Array();
   menus_link[4][0]['url']="http://soft.yesky.com/SoftChannel/72357760712310784/index.shtml";

      menus[4][0][0]="Word"; 
      menus_link[4][0][0]="http://soft.yesky.com/SoftChannel/72357786549223424/index.shtml";
      menus[4][0][1]="Excel";
      menus_link[4][0][1]="http://soft.yesky.com/SoftChannel/72357786515668992/index.shtml";
      menus[4][0][2]="Powerpint";
      menus_link[4][0][2]="http://soft.yesky.com/SoftChannel/72357786532446208/index.shtml";
      menus[4][0][3]="Access";
      menus_link[4][0][3]="http://soft.yesky.com/SoftChannel/72357786498891776/index.shtml";
      menus[4][0][4]="����";
      menus_link[4][0][4]="http://soft.yesky.com/SoftChannel/72357786566000640/index.shtml";


   menus[4][1]=new Array();                
   menus[4][1]['main']="��ɽϵ��";
   menus[4][1]['width']=90;
   menus_link[4][1]=new Array();
   menus_link[4][1]['url']="http://soft.yesky.com/SoftChannel/72357795072049152/index.shtml";

      menus[4][1][0]="��ɽ����";
      menus_link[4][1][0]="http://soft.yesky.com/SoftChannel/72357795088826368/index.shtml";
      menus[4][1][1]="��ɽ�ʼ�";
      menus_link[4][1][1]="http://soft.yesky.com/SoftChannel/72357795105603584/index.shtml";
      menus[4][1][2]="��ɽ���";
      menus_link[4][1][2]="http://soft.yesky.com/SoftChannel/72357795139158016/index.shtml";
      menus[4][1][3]="��ɽ��ʾ";
      menus_link[4][1][3]="http://soft.yesky.com/SoftChannel/72357795155935232/index.shtml";
      menus[4][1][4]="����";
      menus_link[4][1][4]="http://soft.yesky.com/SoftChannel/72357795122380800/index.shtml";

   menus[4][2]=new Array();                
   menus[4][2]['main']="��ҵӦ��";
   menus[4][2]['width']=90;
   menus_link[4][2]=new Array();
   menus_link[4][2]['url']="http://soft.yesky.com/SoftChannel/72357790777081856/index.shtml";
      menus[4][2][0]="�칫����";
      menus_link[4][2][0]="http://soft.yesky.com/SoftChannel/72357790810636288/index.shtml";
      menus[4][2][1]="�������";
      menus_link[4][2][1]="http://soft.yesky.com/SoftChannel/72357790827413504/index.shtml";
	  menus[4][2][2]="ѧУӦ��";
      menus_link[4][2][2]="http://soft.yesky.com/SoftChannel/72357790793859072/index.shtml";

   menus[4][3]="��������";
   menus_link[4][3]="http://soft.yesky.com/SoftChannel/72357777892179968/index.shtml";

   menus[4][4]="����";
   menus_link[4][4]="http://soft.yesky.com/SoftChannel/72357782187147264/index.shtml";

   menus[4][5]="���ר��";
   menus_link[4][5]="http://soft.yesky.com/SoftChannel/72348968914255872/index.shtml";

  //----�˵��� ���������


menus[5]['main']="��������";
menus[5]['width']=110;
menus_link[5]['url']="http://soft.yesky.com/SoftChannel/72341268037894144/index.shtml";

   menus[5][0]="Web������";                 
   menus_link[5][0]="http://soft.yesky.com/SoftChannel/72341272332861440/index.shtml";

   menus[5][1]="FTP������";                 
   menus_link[5][1]="http://soft.yesky.com/SoftChannel/72341276627828736/index.shtml";
        
   menus[5][2]="Mail������";                
   menus_link[5][2]="http://soft.yesky.com/SoftChannel/72341280922796032/index.shtml";

   menus[5][3]="�ļ����������";                 
   menus_link[5][3]="http://soft.yesky.com/SoftChannel/72341285217763328/index.shtml";

   menus[5][4]="���ݿ�Ӧ��";                 
   menus_link[5][4]="http://soft.yesky.com/SoftChannel/72341289512730624/index.shtml";

   menus[5][5]="����������";                 
   menus_link[5][5]="http://soft.yesky.com/SoftChannel/72341345347305472/index.shtml";
  
   menus[5][6]="Windows��Ӫ";                 
   menus_link[5][6]="http://soft.yesky.com/SoftChannel/72341298102665216/index.shtml";

   menus[5][7]="Linuxϵ��";                 
   menus_link[5][7]="http://soft.yesky.com/SoftChannel/72341302397632512/index.shtml";

   menus[5][8]="Unixϵ��";                 
   menus_link[5][8]="http://soft.yesky.com/SoftChannel/72341310987567104/index.shtml";

   menus[5][9]="·����Ӧ��";                 
   menus_link[5][9]="http://soft.yesky.com/SoftChannel/72341341069115392/index.shtml";

   menus[5][10]="���������";                 
   menus_link[5][10]="http://soft.yesky.com/SoftChannel/72341341085892608/index.shtml";

   menus[5][11]="�������񷽰�";                 
   menus_link[5][11]="http://soft.yesky.com/SoftChannel/72341349642272768/index.shtml";

   menus[5][12]="��ҵE������";                 
   menus_link[5][12]="http://soft.yesky.com/SoftChannel/72341323872468992/index.shtml";

   menus[5][13]="���Ž������";                 
   menus_link[5][13]="http://soft.yesky.com/SoftChannel/72341332462403584/index.shtml";

   menus[5][14]="У԰�����跽��";                 
   menus_link[5][14]="http://soft.yesky.com/SoftChannel/72341293807697920/index.shtml";

  //----�˵��� ���簲ȫ

menus[6]['main']="���簲ȫ��";
menus[6]['width']=80;
menus_link[6]['url']="http://soft.yesky.com/SoftChannel/72356661200683008/index.shtml";

   menus[6][0]="��������"; 
   menus_link[6][0]="http://soft.yesky.com/SoftChannel/72356678380552192/index.shtml";

   menus[6][1]="��ȫ��ժ";                
   menus_link[6][1]="http://soft.yesky.com/SoftChannel/72356682675519488/index.shtml";
        
   menus[6][2]="ϵͳ©��"; 
   menus_link[6][2]="http://soft.yesky.com/SoftChannel/72356704150355968/index.shtml";

   menus[6][3]="��ȫ����";
   menus_link[6][3]="http://soft.yesky.com/SoftChannel/72356695560421376/index.shtml";
 
   menus[6][4]="�ڿͼ���"; 
   menus_link[6][4]="http://soft.yesky.com/SoftChannel/72356665495650304/index.shtml";

   menus[6][5]="�����ֲ�";
   menus_link[6][5]="http://soft.yesky.com/SoftChannel/72356686970486784/index.shtml";

   menus[6][6]="����ǽ";
   menus_link[6][6]="http://soft.yesky.com/SoftChannel/72356669790617600/index.shtml";

   menus[6][7]="��ȫ����";
   menus_link[6][7]="http://soft.yesky.com/SoftChannel/72356674085584896/index.shtml";

   menus[6][8]="��ȫ����";
   menus_link[6][8]="http://soft.yesky.com/SoftChannel/72356708445323264/index.shtml";

  
  //----�˵��� ר��̳�


menus[7]['main']="ר��̡̳�";
menus[7]['width']=80;
menus_link[7]['url']="http://soft.yesky.com/SoftChannel/72348964619288576/index.shtml";

   menus[7][0]="��ҳ���";                 
   menus_link[7][0]="http://soft.yesky.com/SoftChannel/72348990389092352/index.shtml";

   menus[7][1]="ͼ��ͼ��";                 
   menus_link[7][1]="http://soft.yesky.com/SoftChannel/72348986094125056/index.shtml";
        
   menus[7][2]="�칫����";                
   menus_link[7][2]="http://soft.yesky.com/SoftChannel/72348968914255872/index.shtml";

   menus[7][3]="���򿪷�";                 
   menus_link[7][3]="http://soft.yesky.com/SoftChannel/72348977504190464/index.shtml";

   menus[7][4]="���Ӧ��";                 
   menus_link[7][4]="http://soft.yesky.com/SoftChannel/72348981799157760/index.shtml";

   menus[7][5]="����ϵͳ";                 
   menus_link[7][5]="http://soft.yesky.com/SoftChannel/72348973209223168/index.shtml";
  
   menus[7][6]="�ձ��ܿ�";                 
   menus_link[7][6]="http://soft.yesky.com/SoftChannel/72348994684059648/index.shtml";

  
// Start HTML Code -------------
document.writeln("<table cellpadding=0 cellspacing=0 width=100% height=20 id=menuTable>");
document.writeln("  <tr>");
document.writeln("    <td width=12 class=menu_bg>&nbsp;</td>");
document.writeln("    <td>");
document.writeln("	  <div style='position:absolute;width:0px;height:0px;overflow:visible;'z-index:90>");
// End HTML Code -------------

		  for(i=0;i<menus_num;i++)
		  {
		    document.writeln("<div style='position:absolute;width:"+menus[i]['width']+";height:"+(menus[i].length*21+8)+";left:"+
			menu_width*i+";top:10px;border:1px solid #078399;visibility:hidden;background-color:#F8F8F8;z-index:99' id=menus_"+i+
			" onmouseover='menuOver(menuTable.cells["+(i+2)+"],this)' onmouseout='menuOut(menuTable.cells["+(i+2)+"],this)'>");
			for(j=0;j<menus[i].length;j++) //color
			{
			  if(menus[i][j]['main'])
			  {
			    var tem="<div style='position:absolute;left:"+(menus[i]['width']-5)+"px;top:"+(21*j+4)+
				"px;z-index:102;visibility:hidden;width:"+menus[i][j]['width']+"px;height:"+(menus[i][j].length*21+8)+
				"px;border:1px solid #078399;background-color:#F8F8F8;' id=menus_"+i+"_"+j+" onmouseover='cMenuOver(cMenuTable_"+i+
				".cells["+j+"],this)' onmouseout='cMenuOut(cMenuTable_"+i+".cells["+j+"],this)'>"
			    document.writeln(tem);
				document.writeln("  <table style='position:relative;top:3px;z-index:100' cellpadding=1 cellspacing=1 width="+
			    (menus[i]['width']-6)+" align=center>");
				for(k=0;k<menus[i][j].length;k++)
				{
				  document.writeln("<tr>");
			      document.writeln("  <td align=center height=20 style='cursor:hand;' onmouseover=\"this.className='c_menu_over'\""+
				  " onmouseout=\"this.className='c_menu'\" onclick=window.open('"+menus_link[i][j][k]+"')><span>"+menus[i][j][k]+
				  "</span></td>");
			      document.writeln("</tr>");
				}
				document.writeln("  </table>");
				document.writeln("</div>");
				document.writeln("<div style='position:absolute;left:"+(menus[i]['width']-15)+"px;top:"+(21*j+7)+
				"px;z-index:102;width:4px;height:7px;' onmouseover='cMenuOver(cMenuTable_"+i+".cells["+j+"],menus_"+i+"_"+j+
				")' onmouseout='cMenuOut(cMenuTable_"+i+".cells["+j+"],menus_"+i+"_"+j+")'>");
				document.writeln("  <img src=http://soft.yesky.com/imagesnew/software/iframe/navigation/images/right.gif width=4 height=7>");
				document.writeln("</div>");
			  }
			}
			document.writeln("  <table style='position:relative;top:3px;z-index:100' cellpadding=1 cellspacing=1 width="+
			(menus[i]['width']-6)+" align=center id=cMenuTable_"+i+">");
			for(j=0;j<menus[i].length;j++)
			{
			  if(menus[i][j]['main'])
			  {
			    document.writeln("<tr>");
			    document.writeln("  <td align=center height=20 style='cursor:hand;' onmouseover='cMenuOver(this,menus_"+i+"_"+j+
				");' onmouseout='cMenuOut(this,menus_"+i+"_"+j+")' onclick=window.open('"+menus_link[i][j]['url']+"')><span class=shadow>"+
				menus[i][j]['main']+"</span></td>");  //update 030311
			    document.writeln("</tr>");
			  }
			  else
			  {
			    document.writeln("<tr>");
			    document.writeln("  <td align=center height=20 style='cursor:hand;' onmouseover=\"this.className='c_menu_over'\""+
				" onmouseout=\"this.className='c_menu'\" onclick=window.open('"+menus_link[i][j]+"')><span>"+menus[i][j]+"</span></td>"); // shiny update
			    document.writeln("</tr>");
			  }
			}
			document.writeln("  </table>");
			document.writeln("</div>");
		  }

// Start HTML Code -------------
document.writeln("      </div>");
document.writeln("	</td>");
// End HTML Code -------------


	  for(i=0;i<menus_num;i++)
	  {
	    document.writeln("<td bgcolor=#eeeeee width="+menu_width+" class=menu_bg align=center style='cursor:hand;filter: dropshadow(color=#ff0000,offx=1,offy=1);'"+
		"onmouseover='menuOver(this,menus_"+i+")' onmouseout='menuOut(this,menus_"+i+")'>");
		//document.writeln("  <span>"+menus[i]['main']+"</span>");  //old
	    //document.writeln("  <span><a href="+menus_link[i]+" target=_blank>"+menus[i]['main']+"</a></span>");  //shiny add1
		document.writeln("  <span><a onClick=window.open('"+menus_link[i]['url']+"') style='cursor:hand'><font color=#ffffff>"+menus[i]['main']+"</font></a></span>");  //font color

		document.writeln("</td>");
	  }

// Start HTML Code -------------
document.writeln("	<td class=menu_bg>&nbsp;</td>");
document.writeln("  </tr>");
document.writeln("</table>");
// End HTML Code -------------
