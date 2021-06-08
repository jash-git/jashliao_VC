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

//--- 主菜单一 ----

menus[0]['main']="设计在线↓";                //栏目名称
menus[0]['width']=90;
menus_link[0]['url']="http://soft.yesky.com/SoftChannel/72351163642544128/index.shtml";

   menus[0][0]=new Array();                 //子菜单1 注意menus[0][0]的下标变化
   menus[0][0]['main']="网页陶吧";
   menus[0][0]['width']=90;
   menus_link[0][0]=new Array();
   menus_link[0][0]['url']="http://soft.yesky.com/SoftChannel/72351167937511424/index.shtml";

      menus[0][0][0]="网页工具";          //叶子菜单
      menus_link[0][0][0]="http://soft.yesky.com/SoftChannel/72351168004620288/index.shtml";
      menus[0][0][1]="Dreamweaver";          //叶子菜单
      menus_link[0][0][1]="http://soft.yesky.com/SoftChannel/72351168004685824/index.shtml";
      menus[0][0][2]="FrontPage";
      menus_link[0][0][2]="http://soft.yesky.com/SoftChannel/72351168004816896/index.shtml";
      menus[0][0][3]="Fireworks";
      menus_link[0][0][3]="http://soft.yesky.com/SoftChannel/72351168005013504/index.shtml";
      menus[0][0][4]="GOLIVE";
      menus_link[0][0][4]="http://soft.yesky.com/SoftChannel/72351168004882432/index.shtml";
      menus[0][0][5]="其它工具";
      menus_link[0][0][5]="http://soft.yesky.com/SoftChannel/72351168004947968/index.shtml";
      menus[0][0][6]="设计理念";
      menus_link[0][0][6]="http://soft.yesky.com/SoftChannel/72351168038174720/index.shtml";
   //------

   menus[0][1]=new Array();                   //子菜单2  注意menus[0][1]的下标变化
   menus[0][1]['main']="网页技术";
   menus[0][1]['width']=90;
   menus_link[0][1]=new Array();
   menus_link[0][1]['url']="http://soft.yesky.com/SoftChannel/72351167954288640/index.shtml";

      menus[0][1][0]="CSS";
      menus_link[0][1][0]="http://soft.yesky.com/SoftChannel/72351167954354176/index.shtml";

      menus[0][1][1]="HTML";
      menus_link[0][1][1]="http://soft.yesky.com/SoftChannel/72351167954485248/index.shtml";

      menus[0][1][2]="JavaScript";
      menus_link[0][1][2]="http://soft.yesky.com/SoftChannel/72351167954419712/index.shtml";
      menus[0][1][3]="服务器端";
      menus_link[0][1][3]="http://soft.yesky.com/SoftChannel/72351167954616320/index.shtml";
      menus[0][1][4]="XML";
      menus_link[0][1][4]="http://soft.yesky.com/SoftChannel/72351167954747392/index.shtml";
      menus[0][1][5]="技巧点滴";
      menus_link[0][1][5]="http://soft.yesky.com/SoftChannel/72351167954550784/index.shtml";
      menus[0][1][6]="其他技术";
      menus_link[0][1][6]="http://soft.yesky.com/SoftChannel/72351167954812928/index.shtml";
   //---
   menus[0][2]=new Array();                   //子菜单3  美工教室
   menus[0][2]['main']="美工教室";
   menus[0][2]['width']=90;
   menus_link[0][2]=new Array();
   menus_link[0][2]['url']="http://soft.yesky.com/SoftChannel/72351172232478720/index.shtml";

      menus[0][2][0]="平面设计";
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
      menus[0][2][8]="其他";
      menus_link[0][2][8]="http://soft.yesky.com/SoftChannel/72351172283269120/index.shtml";
      menus[0][2][9]="3DS Max";
      menus_link[0][2][9]="http://soft.yesky.com/SoftChannel/72351172266098688/index.shtml";
      menus[0][2][10]="AutoCAD";
      menus_link[0][2][10]="http://soft.yesky.com/SoftChannel/72351172266164224/index.shtml";
      menus[0][2][11]="基础知识";
      menus_link[0][2][11]="http://soft.yesky.com/SoftChannel/72351172249255936/index.shtml";

   //--- Flash---
   menus[0][3]=new Array();                   //子菜单4 
   menus[0][3]['main']="Flash";
   menus[0][3]['width']=90;
   menus_link[0][3]=new Array();
   menus_link[0][3]['url']="http://soft.yesky.com/SoftChannel/72351185117380608/index.shtml";

      menus[0][3][0]="基础教程";
      menus_link[0][3][0]="http://soft.yesky.com/SoftChannel/72351185134157824/index.shtml";
      menus[0][3][1]="技巧运用";
      menus_link[0][3][1]="http://soft.yesky.com/SoftChannel/72351185150935040/index.shtml";
      menus[0][3][2]="实例剖析";
      menus_link[0][3][2]="http://soft.yesky.com/SoftChannel/72351185184489472/index.shtml";
      menus[0][3][3]="周边辅助";
      menus_link[0][3][3]="http://soft.yesky.com/SoftChannel/72351185201266688/index.shtml";
      menus[0][3][4]="佳作欣赏";
      menus_link[0][3][4]="http://soft.yesky.com/SoftChannel/72351185167712256/index.shtml";

//－－多媒体

   menus[0][4]=new Array();                   //子菜单4 
   menus[0][4]['main']="多媒体";
   menus[0][4]['width']=90;
   menus_link[0][4]=new Array();
   menus_link[0][4]['url']="http://soft.yesky.com/SoftChannel/72351180822413312/index.shtml";

      menus[0][4][0]="Authorware";
      menus_link[0][4][0]="http://soft.yesky.com/SoftChannel/72351180839190528/index.shtml";
      menus[0][4][1]="Director";
      menus_link[0][4][1]="http://soft.yesky.com/SoftChannel/72351180855967744/index.shtml";
      menus[0][4][2]="视频处理";
      menus_link[0][4][2]="http://soft.yesky.com/SoftChannel/72351180872744960/index.shtml";
      menus[0][4][3]="其他";
      menus_link[0][4][3]="http://soft.yesky.com/SoftChannel/72351180889522176/index.shtml";


   menus[0][5]="精品赏析";
   menus_link[0][5]="http://soft.yesky.com/SoftChannel/72351176527446016/index.shtml";

   menus[0][6]="图像专题";
   menus_link[0][6]="http://soft.yesky.com/SoftChannel/72348986094125056/index.shtml";

   menus[0][7]="网页专题";
   menus_link[0][7]="http://soft.yesky.com/SoftChannel/72348990389092352/index.shtml";



//--- 主菜单二 实用软件咨询----

menus[1]['main']="工具软件↓";                
menus[1]['width']=100;
menus_link[1]['url']="http://soft.yesky.com/SoftChannel/72347865107660800/index.shtml";

   menus[1][0]=new Array();                 
   menus[1][0]['main']="系统工具";
   menus[1][0]['width']=90;
   menus_link[1][0]=new Array();
   menus_link[1][0]['url']="http://soft.yesky.com/SoftChannel/72347869402628096/index.shtml";

      menus[1][0][0]="系统优化";          
      menus_link[1][0][0]="http://soft.yesky.com/SoftChannel/72347869419405312/index.shtml";

      menus[1][0][1]="硬件相关";
      menus_link[1][0][1]="http://soft.yesky.com/SoftChannel/72347869469736960/index.shtml";

   menus[1][1]=new Array();                   
   menus[1][1]['main']="网络工具";
   menus[1][1]['width']=90;
   menus_link[1][1]=new Array();
   menus_link[1][1]['url']="http://soft.yesky.com/SoftChannel/72347873697595392/index.shtml";

      menus[1][1][0]="网络浏览";
      menus_link[1][1][0]="http://soft.yesky.com/SoftChannel/72347873714372608/index.shtml";
      menus[1][1][1]="网络交流";
      menus_link[1][1][1]="http://soft.yesky.com/SoftChannel/72347873764704256/index.shtml";
      menus[1][1][2]="网络构建";
      menus_link[1][1][2]="http://soft.yesky.com/SoftChannel/72347873781481472/index.shtml";
	  menus[1][1][3]="邮件处理";
      menus_link[1][1][3]="http://soft.yesky.com/SoftChannel/72347873798258688/index.shtml";
      menus[1][1][4]="网络工具";
      menus_link[1][1][4]="http://soft.yesky.com/SoftChannel/72347873815035904/index.shtml";

   menus[1][2]=new Array();                   
   menus[1][2]['main']="媒体播放";
   menus[1][2]['width']=90;
   menus_link[1][2]=new Array();
   menus_link[1][2]['url']="http://soft.yesky.com/SoftChannel/72346765596033024/index.shtml";

      menus[1][2][0]="流媒体";
      menus_link[1][2][0]="http://soft.yesky.com/SoftChannel/72346769891000320/index.shtml";
      menus[1][2][1]="工具与制作";
      menus_link[1][2][1]="http://soft.yesky.com/SoftChannel/72346774185967616/index.shtml";
      menus[1][2][2]="视频播放";
      menus_link[1][2][2]="http://soft.yesky.com/SoftChannel/72346778480934912/index.shtml";
      menus[1][2][3]="音频播放";
      menus_link[1][2][3]="http://soft.yesky.com/SoftChannel/72346782775902208/index.shtml";


   menus[1][3]=new Array();                   
   menus[1][3]['main']="专用软件";
   menus[1][3]['width']=90;
   menus_link[1][3]=new Array();
   menus_link[1][3]['url']="http://soft.yesky.com/SoftChannel/72347899467399168/index.shtml";

      menus[1][3][0]="博彩软件";
      menus_link[1][3][0]="http://soft.yesky.com/SoftChannel/72347899500953600/index.shtml";
      menus[1][3][1]="财务管理";
      menus_link[1][3][1]="http://soft.yesky.com/SoftChannel/72347899517730816/index.shtml";
      menus[1][3][2]="教育软件";
      menus_link[1][3][2]="http://soft.yesky.com/SoftChannel/72347899484176384/index.shtml";
      menus[1][3][3]="网吧管理";
      menus_link[1][3][3]="http://soft.yesky.com/SoftChannel/72347899534508032/index.shtml";


   menus[1][4]=new Array();                   
   menus[1][4]['main']="休闲软件";
   menus[1][4]['width']=90;
   menus_link[1][4]=new Array();
   menus_link[1][4]['url']="http://soft.yesky.com/SoftChannel/72347903762366464/index.shtml";
      menus[1][4][0]="游戏天地";
      menus_link[1][4][0]="http://soft.yesky.com/SoftChannel/72347903795920896/index.shtml";
      menus[1][4][1]="桌面趣味";
      menus_link[1][4][1]="http://soft.yesky.com/SoftChannel/72347903779143680/index.shtml";


   menus[1][5]="磁盘工具";
   menus_link[1][5]="http://soft.yesky.com/SoftChannel/72347877992562688/index.shtml";
   menus[1][6]="光盘工具";
   menus_link[1][6]="http://soft.yesky.com/SoftChannel/72347908057333760/index.shtml";
   menus[1][7]="图像工具";
   menus_link[1][7]="http://soft.yesky.com/SoftChannel/72347882287529984/index.shtml";
   menus[1][8]="文件工具";
   menus_link[1][8]="http://soft.yesky.com/SoftChannel/72347886582497280/index.shtml";
   menus[1][9]="安全工具";
   menus_link[1][9]="http://soft.yesky.com/SoftChannel/72347895172431872/index.shtml";
   menus[1][10]="其他工具";
   menus_link[1][10]="http://soft.yesky.com/SoftChannel/72347890877464576/index.shtml";

// ----主菜单三 开发者网络

menus[2]['main']="程序开发↓";                
menus[2]['width']=90;
menus_link[2]['url']="http://soft.yesky.com/SoftChannel/72342367549521920/index.shtml";


 menus[2][0]=new Array();    
 menus[2][0]['main']="开发工具";
 menus[2][0]['width']=90;
 menus_link[2][0]=new Array();
 menus_link[2][0]['url']="http://soft.yesky.com/SoftChannel/72342371844489216/index.shtml";

  menus[2][0][0]="Java";
  menus_link[2][0][0]="http://soft.yesky.com/SoftChannel/72342371961929728/index.shtml";

  menus[2][0][1]="开发专栏";
  menus_link[2][0][1]="http://soft.yesky.com/SoftChannel/72342371928375296/index.shtml";

  menus[2][0][2]="服务器脚本编程";
  menus_link[2][0][2]="http://soft.yesky.com/SoftChannel/72342371945152512/index.shtml";

  menus[2][0][3]="嵌入式开发";
  menus_link[2][0][3]="http://soft.yesky.com/SoftChannel/72342371878043648/index.shtml";

  menus[2][0][4]="系统编程";
  menus_link[2][0][4]="http://soft.yesky.com/SoftChannel/72342371911598080/index.shtml";

  menus[2][0][5]="新手上路";
  menus_link[2][0][5]="http://soft.yesky.com/SoftChannel/72342371861266432/index.shtml";

 menus[2][1]=new Array();                   
 menus[2][1]['main']="微软开发";
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

  menus[2][1][6]="技术专题";
  menus_link[2][1][6]="http://soft.yesky.com/SoftChannel/72342380484755456/index.shtml";

  menus[2][1][7]="动态播报";
  menus_link[2][1][7]="http://soft.yesky.com/SoftChannel/72342380451201024/index.shtml";

 menus[2][2]=new Array();               
 menus[2][2]['main']="技术追踪";
 menus[2][2]['width']=90;
 menus_link[2][2]=new Array();
 menus_link[2][2]['url']="http://soft.yesky.com/SoftChannel/72342376139456512/index.shtml";

  menus[2][2][0]="XML与.Net";
  menus_link[2][2][0]="http://soft.yesky.com/SoftChannel/72342376223342592/index.shtml";

  menus[2][2][1]="技术理论";
  menus_link[2][2][1]="http://soft.yesky.com/SoftChannel/72342376173010944/index.shtml";
 
  menus[2][2][2]="系统分析";
  menus_link[2][2][2]="http://soft.yesky.com/SoftChannel/72342376189788160/index.shtml";

  menus[2][2][3]="新技术应用";
  menus_link[2][2][3]="http://soft.yesky.com/SoftChannel/72342376156233728/index.shtml";

 menus[2][3]=new Array();               
 menus[2][3]['main']="软件工程";
 menus[2][3]['width']=90;
 menus_link[2][3]=new Array();
 menus_link[2][3]['url']="http://soft.yesky.com/SoftChannel/72342393319325696/index.shtml";

  menus[2][3][0]="需求工程";
  menus_link[2][3][0]="http://soft.yesky.com/SoftChannel/72342393336102912/index.shtml";
  menus[2][3][1]="项目管理";
  menus_link[2][3][1]="http://soft.yesky.com/SoftChannel/72342393352880128/index.shtml";
  menus[2][3][2]="软件测试";
  menus_link[2][3][2]="http://soft.yesky.com/SoftChannel/72342393369657344/index.shtml";
  menus[2][3][3]="软件文档";
  menus_link[2][3][3]="http://soft.yesky.com/SoftChannel/72342393386434560/index.shtml";

 menus[2][4]="案例分析";
 menus_link[2][4]="http://soft.yesky.com/SoftChannel/72342397614292992/index.shtml";
 menus[2][5]="程序人生";
 menus_link[2][5]="http://soft.yesky.com/SoftChannel/72342389024358400/index.shtml";


  //----菜单四   操作系统

menus[3]['main']="操作系统↓";
menus[3]['width']=90;
menus_link[3]['url']="http://soft.yesky.com/SoftChannel/72350064130916352/index.shtml";

   menus[3][0]="Windows_XP"                 //子菜单1 注意menus[3][0]的下标变化
   menus_link[3][0]="http://soft.yesky.com/SoftChannel/72350085605752832/index.shtml";

   menus[3][1]="Win2000/NT"                 //子菜单1 注意menus[3][0]的下标变化
   menus_link[3][1]="http://soft.yesky.com/SoftChannel/72350077015818240/index.shtml";
   menus[3][2]="Win9x/Me"                 
   menus_link[3][2]="http://soft.yesky.com/SoftChannel/72350072720850944/index.shtml";
   menus[3][3]="Win2003";          
   menus_link[3][3]="http://soft.yesky.com/SoftChannel/72350094195687424/index.shtml";

   menus[3][4]="Linux开发";
   menus_link[3][4]="http://soft.yesky.com/SoftChannel/72350081327562752/index.shtml"; 
   menus[3][5]="Linux配置";
   menus_link[3][5]="http://soft.yesky.com/SoftChannel/72350081361117184/index.shtml";
   menus[3][6]="Linux学习";
   menus_link[3][6]="http://soft.yesky.com/SoftChannel/72350081344339968/index.shtml";
   menus[3][7]="Linux世界";
   menus_link[3][7]="http://soft.yesky.com/SoftChannel/72350081394671616/index.shtml";
   menus[3][8]="Linux应用";          
   menus_link[3][8]="http://soft.yesky.com/SoftChannel/72350081377894400/index.shtml";

   menus[3][9]="其它操作系统"                 
   menus_link[3][9]="http://soft.yesky.com/SoftChannel/72350068425883648/index.shtml";
   menus[3][10]="系统工具"                 
   menus_link[3][10]="http://soft.yesky.com/SoftChannel/72350089900720128/index.shtml";


//菜单五 办公软件

menus[4]['main']="办公软件↓";                //栏目名称
menus[4]['width']=90;
menus_link[4]['url']="http://soft.yesky.com/SoftChannel/72357760712310784/index.shtml";

   menus[4][0]=new Array();                 //子菜单1 注意menus[4][0]的下标变化
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
      menus[4][0][4]="其他";
      menus_link[4][0][4]="http://soft.yesky.com/SoftChannel/72357786566000640/index.shtml";


   menus[4][1]=new Array();                
   menus[4][1]['main']="金山系列";
   menus[4][1]['width']=90;
   menus_link[4][1]=new Array();
   menus_link[4][1]['url']="http://soft.yesky.com/SoftChannel/72357795072049152/index.shtml";

      menus[4][1][0]="金山文字";
      menus_link[4][1][0]="http://soft.yesky.com/SoftChannel/72357795088826368/index.shtml";
      menus[4][1][1]="金山邮件";
      menus_link[4][1][1]="http://soft.yesky.com/SoftChannel/72357795105603584/index.shtml";
      menus[4][1][2]="金山表格";
      menus_link[4][1][2]="http://soft.yesky.com/SoftChannel/72357795139158016/index.shtml";
      menus[4][1][3]="金山演示";
      menus_link[4][1][3]="http://soft.yesky.com/SoftChannel/72357795155935232/index.shtml";
      menus[4][1][4]="其他";
      menus_link[4][1][4]="http://soft.yesky.com/SoftChannel/72357795122380800/index.shtml";

   menus[4][2]=new Array();                
   menus[4][2]['main']="行业应用";
   menus[4][2]['width']=90;
   menus_link[4][2]=new Array();
   menus_link[4][2]['url']="http://soft.yesky.com/SoftChannel/72357790777081856/index.shtml";
      menus[4][2][0]="办公文秘";
      menus_link[4][2][0]="http://soft.yesky.com/SoftChannel/72357790810636288/index.shtml";
      menus[4][2][1]="财务管理";
      menus_link[4][2][1]="http://soft.yesky.com/SoftChannel/72357790827413504/index.shtml";
	  menus[4][2][2]="学校应用";
      menus_link[4][2][2]="http://soft.yesky.com/SoftChannel/72357790793859072/index.shtml";

   menus[4][3]="技巧荟萃";
   menus_link[4][3]="http://soft.yesky.com/SoftChannel/72357777892179968/index.shtml";

   menus[4][4]="其他";
   menus_link[4][4]="http://soft.yesky.com/SoftChannel/72357782187147264/index.shtml";

   menus[4][5]="相关专题";
   menus_link[4][5]="http://soft.yesky.com/SoftChannel/72348968914255872/index.shtml";

  //----菜单六 服务器软件


menus[5]['main']="服务器↓";
menus[5]['width']=110;
menus_link[5]['url']="http://soft.yesky.com/SoftChannel/72341268037894144/index.shtml";

   menus[5][0]="Web服务器";                 
   menus_link[5][0]="http://soft.yesky.com/SoftChannel/72341272332861440/index.shtml";

   menus[5][1]="FTP服务器";                 
   menus_link[5][1]="http://soft.yesky.com/SoftChannel/72341276627828736/index.shtml";
        
   menus[5][2]="Mail服务器";                
   menus_link[5][2]="http://soft.yesky.com/SoftChannel/72341280922796032/index.shtml";

   menus[5][3]="文件共享服务器";                 
   menus_link[5][3]="http://soft.yesky.com/SoftChannel/72341285217763328/index.shtml";

   menus[5][4]="数据库应用";                 
   menus_link[5][4]="http://soft.yesky.com/SoftChannel/72341289512730624/index.shtml";

   menus[5][5]="域名服务器";                 
   menus_link[5][5]="http://soft.yesky.com/SoftChannel/72341345347305472/index.shtml";
  
   menus[5][6]="Windows阵营";                 
   menus_link[5][6]="http://soft.yesky.com/SoftChannel/72341298102665216/index.shtml";

   menus[5][7]="Linux系列";                 
   menus_link[5][7]="http://soft.yesky.com/SoftChannel/72341302397632512/index.shtml";

   menus[5][8]="Unix系列";                 
   menus_link[5][8]="http://soft.yesky.com/SoftChannel/72341310987567104/index.shtml";

   menus[5][9]="路由器应用";                 
   menus_link[5][9]="http://soft.yesky.com/SoftChannel/72341341069115392/index.shtml";

   menus[5][10]="代理服务器";                 
   menus_link[5][10]="http://soft.yesky.com/SoftChannel/72341341085892608/index.shtml";

   menus[5][11]="电子政务方案";                 
   menus_link[5][11]="http://soft.yesky.com/SoftChannel/72341349642272768/index.shtml";

   menus[5][12]="企业E化方案";                 
   menus_link[5][12]="http://soft.yesky.com/SoftChannel/72341323872468992/index.shtml";

   menus[5][13]="电信解决方案";                 
   menus_link[5][13]="http://soft.yesky.com/SoftChannel/72341332462403584/index.shtml";

   menus[5][14]="校园网建设方案";                 
   menus_link[5][14]="http://soft.yesky.com/SoftChannel/72341293807697920/index.shtml";

  //----菜单七 网络安全

menus[6]['main']="网络安全↓";
menus[6]['width']=80;
menus_link[6]['url']="http://soft.yesky.com/SoftChannel/72356661200683008/index.shtml";

   menus[6][0]="病毒剖析"; 
   menus_link[6][0]="http://soft.yesky.com/SoftChannel/72356678380552192/index.shtml";

   menus[6][1]="安全文摘";                
   menus_link[6][1]="http://soft.yesky.com/SoftChannel/72356682675519488/index.shtml";
        
   menus[6][2]="系统漏洞"; 
   menus_link[6][2]="http://soft.yesky.com/SoftChannel/72356704150355968/index.shtml";

   menus[6][3]="安全技术";
   menus_link[6][3]="http://soft.yesky.com/SoftChannel/72356695560421376/index.shtml";
 
   menus[6][4]="黑客技术"; 
   menus_link[6][4]="http://soft.yesky.com/SoftChannel/72356665495650304/index.shtml";

   menus[6][5]="网管手册";
   menus_link[6][5]="http://soft.yesky.com/SoftChannel/72356686970486784/index.shtml";

   menus[6][6]="防火墙";
   menus_link[6][6]="http://soft.yesky.com/SoftChannel/72356669790617600/index.shtml";

   menus[6][7]="安全工具";
   menus_link[6][7]="http://soft.yesky.com/SoftChannel/72356674085584896/index.shtml";

   menus[6][8]="安全故事";
   menus_link[6][8]="http://soft.yesky.com/SoftChannel/72356708445323264/index.shtml";

  
  //----菜单八 专题教程


menus[7]['main']="专题教程↓";
menus[7]['width']=80;
menus_link[7]['url']="http://soft.yesky.com/SoftChannel/72348964619288576/index.shtml";

   menus[7][0]="网页设计";                 
   menus_link[7][0]="http://soft.yesky.com/SoftChannel/72348990389092352/index.shtml";

   menus[7][1]="图形图像";                 
   menus_link[7][1]="http://soft.yesky.com/SoftChannel/72348986094125056/index.shtml";
        
   menus[7][2]="办公上网";                
   menus_link[7][2]="http://soft.yesky.com/SoftChannel/72348968914255872/index.shtml";

   menus[7][3]="程序开发";                 
   menus_link[7][3]="http://soft.yesky.com/SoftChannel/72348977504190464/index.shtml";

   menus[7][4]="软件应用";                 
   menus_link[7][4]="http://soft.yesky.com/SoftChannel/72348981799157760/index.shtml";

   menus[7][5]="操作系统";                 
   menus_link[7][5]="http://soft.yesky.com/SoftChannel/72348973209223168/index.shtml";
  
   menus[7][6]="日报周刊";                 
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
