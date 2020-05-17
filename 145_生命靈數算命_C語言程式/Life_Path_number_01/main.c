#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int intCount[10];//每個數字出現的個數
    int intYear;
    int intMonth;
    int intDay;
    int i;
    printf("個人生命靈數計算：\n");
    printf("請依序輸入您的生日\n");
    printf("請輸入西元年（ex：1901）\t");
    scanf("%d",&intYear);
    printf("請輸入月份（ex：11）\t");
    scanf("%d",&intMonth);
    printf("請輸入日期（ex：28）\t");
    scanf("%d",&intDay);
    printf("您的生日：%d/%d/%d\n",intYear,intMonth,intDay);

    for(i=0;i<10;i++)
    {
        intCount[i]=0;
    }
    int intQuotient=0;
    int intRemainder=0;
    int j;
    intRemainder=intYear;
    for(i=0;i<4;i++)
    {
        j=pow(10,i);
        intQuotient=(intRemainder*j)/1000;
        intCount[intQuotient]++;
        intRemainder=(intRemainder*j)%1000/j;
    }
    intRemainder=intMonth;
    intQuotient=intRemainder/10;
    intCount[intQuotient]++;
    intRemainder=intRemainder%10;
    intCount[intRemainder]++;

    intRemainder=intDay;
    intQuotient=intRemainder/10;
    intCount[intQuotient]++;
    intRemainder=intRemainder%10;
    intCount[intRemainder]++;

    printf("\n先天數：\t");
    for(i=1;i<10;i++)
    {
        if(intCount[i]>0)
        {
            printf("%d,\t",i);
        }
    }
    printf("\n天賦數：\t");
    int intTalent=0;
    for(i=0;i<10;i++)
    {
        if(intCount[i]>0)
        {
            intTalent+=(i*intCount[i]);
        }
    }
    intRemainder=intTalent;
    intQuotient=intRemainder/10;
    intCount[intQuotient]++;
    printf("%d,\t",intQuotient);
    intRemainder=intRemainder%10;
    intCount[intRemainder]++;
    printf("%d,\t",intRemainder);
    printf("\n命數：\t");
    int intMain;
    intMain=intQuotient+intRemainder;
    if(intMain>9)
    {
        intRemainder=intMain;
        intQuotient=intRemainder/10;
        intCount[intQuotient]++;
        printf("%d,\t",intQuotient);
        intRemainder=intRemainder%10;
        intCount[intRemainder]++;

        intMain=intQuotient+intRemainder;
        intCount[intMain]++;
    }
    else
    {
        intCount[intMain]++;
    }
    printf("%d,\n",intMain);

    printf("生日數：\t");
    int intBirthday;
    intRemainder=intDay;
    intQuotient=intRemainder/10;
    intRemainder=intRemainder%10;
    intBirthday=intQuotient+intRemainder;
    if(intBirthday>9)
    {
        intRemainder=intBirthday;
        intQuotient=intRemainder/10;
        intCount[intQuotient]++;
        printf("%d,\t",intQuotient);
        intRemainder=intRemainder%10;
        intCount[intRemainder]++;

        intBirthday=intQuotient+intRemainder;
        intCount[intBirthday]++;
    }
    else
    {
        intCount[intBirthday]++;
    }
    printf("%d,\n",intBirthday);

    printf("星座數：\t");
    int intConstellation=0;
    int intMonth_Day=0;
    intMonth_Day=(intMonth*100)+intDay;
    if((intMonth_Day>=321)&&(intMonth_Day<=419))
    {
        intConstellation=1;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//白羊座 Aries
    }
    if((intMonth_Day>=420)&&(intMonth_Day<=520))
    {
        intConstellation=2;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//金牛座 Taurus
    }
    if((intMonth_Day>=521)&&(intMonth_Day<=621))
    {
        intConstellation=3;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//雙子座 Gemini
    }
    if((intMonth_Day>=622)&&(intMonth_Day<=722))
    {
        intConstellation=4;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//巨蟹座 Cancer
    }
    if((intMonth_Day>=723)&&(intMonth_Day<=822))
    {
        intConstellation=5;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//獅子座 Leo
    }
    if((intMonth_Day>=823)&&(intMonth_Day<=922))
    {
        intConstellation=6;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//處女座 Virgo
    }
    if((intMonth_Day>=923)&&(intMonth_Day<=1022))
    {
        intConstellation=7;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//天秤座 Libra
    }
    if((intMonth_Day>=1023)&&(intMonth_Day<=1121))
    {
        intConstellation=8;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//天蠍座 Scorpio
    }
    if((intMonth_Day>=1122)&&(intMonth_Day<=1221))
    {
        intConstellation=9;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//射手座 Sagittarius
    }
    if((intMonth_Day>=120)&&(intMonth_Day<=218))
    {
        intConstellation=2;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//水瓶座 Aquarius
        intConstellation=11;
    }
    if((intMonth_Day>=219)&&(intMonth_Day<=320))
    {
        intConstellation=3;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//雙魚座 Pieces
        intConstellation=12;
    }
    if(intConstellation==0)
    {
        intConstellation=1;
        intCount[intConstellation]++;
        printf("%d,\n",intConstellation);//摩羯座 Capricorn 12.22-1.19
        intConstellation=10;
    }

    printf("空缺數：\t");
    for(i=1;i<10;i++)
    {
        if(intCount[i]==0)
        {
            printf("%d,\t",i);
        }

    }
    printf("\n");

    printf("以下是你的生命靈數每一個數字的出現次數統計：\n");
    for(i=1;i<10;i++)
    {
        printf("%d\t",i);
    }
    printf("\n");
    for(i=1;i<10;i++)
    {
        printf("%d\t",intCount[i]);
    }
    printf("\n");

    printf("\n以下是依照你命數的個性分析：\n");
    printf("命數：\t%d\n",intMain);
    switch(intMain)
    {
    case 1:
        printf("(自主)	獨立、積極、創造、領導、能量\n");
        printf("優點：富創意與理解力，為人聰明，喜歡領導\n");
        printf("缺點：強勢、獨斷、浮躁、自私、懶散、吹牛。主觀意識強，我行我素，人際關係淡薄\n");
        break;
    case 2:
        printf("(成全)	敏感、體貼、柔順、和諧、依賴\n");
        printf("優點：個性內斂，善於分工合作，重視群體關係，喜歡受到別人肯定\n");
        printf("缺點：情緒不定、優柔寡斷、難以捉摸、膚淺不安。容易因他人的意見而受到影響，不能忍耐孤獨\n");
        break;
    case 3:
        printf("(創意)	行動、樂觀、自信、表現、社交\n");
        printf("優點：聰明機警，有創意，多具有藝術天份，表達能力強	欺瞞、虛榮浮華、憤世嫉俗、渙散不集中\n");
        printf("缺點：。任性，多只依自己的喜好行事，容易好高騭遠\n");
        break;
    case 4:
        printf("(務實)	忠誠、次序、效率、助人、自律\n");
        printf("優點：組織能力強，做事條理分明，目光敏銳，能迅速掌握重點\n");
        printf("缺點：獨斷獨行、心胸狹窄、容易緊張、不易妥協。固執，缺乏安全感，不敢承擔風險，因此容易讓機會溜走\n");
        break;
    case 5:
        printf("(自由)	聰穎、冒險、適應強、多變化、學習快\n");
        printf("優點：能答善辯，口才極佳，熱情豪爽，講義氣，崇尚自由\n");
        printf("缺點：博而不精、持續力差、毫不在乎、索求無度。不喜歡受到束縛，容易放縱，容易得罪別人\n");
        break;
    case 6:
        printf("(責任)	穩定、信賴、熱情、正義、奉獻\n");
        printf("優點：情感細膩，擅長人際間的交際，喜歡幫助他人，重承諾與責任\n");
        printf("缺點：缺乏自信、不切實際、好強爭辯、強行干涉。不理智時，常會做出錯誤的決定，付出不求回報時容易讓自己受傷\n");
        break;
    case 7:
        printf("(探究)	內省、沉默、直覺、真理、理想\n");
        printf("優點：擅長鑽研事物，喜歡追求真理，精於算計，遇事理智\n");
        printf("缺點：冷漠、自大傲慢、自我放縱、鬼鬼祟祟。處事不夠圓滑，不容易被討好，容易到手的東西不會珍惜\n");
        break;
    case 8:
        printf("(權威)	忠貞、持續、堅定、誠懇、照料\n");
        printf("優點：喜歡冒險刺激，有商業頭腦，喜歡追求權力，能即知即行\n");
        printf("缺點：唯物主義、無道德感、心高氣傲、排除他議、驕傲。對喜歡的東西有異常的執著，面對衝突時會勉強自己\n");
        break;
    case 9:
        printf("(可親)	人性、啟發、活力、關懷、靈性\n");
        printf("優點：充滿生命力，能從創意之中獲得滿足感，處事隨機應變，見招拆招\n");
        printf("缺點：卑躬屈膝毫無原則、善於批評、沒有耐性、行事不務實，意志不夠堅定，想像太過於力豐富則會變成天馬行空\n");
        break;
    }

    printf("\n空圈選越多的數字，表示那能力越強烈:\n");
    for(i=1;i<10;i++)
    {
        if(intCount[i]>0)
        {
            printf("%d:\t個數:%d\t",i,intCount[i]);
            switch(i)
            {
            case 1:
                printf("創新/獨立\n");
                break;
            case 2:
                printf("平和/直覺\n");
                break;
            case 3:
                printf("理想/美感\n");
                break;
            case 4:
                printf("安全/秩序\n");
                break;
            case 5:
                printf("自由/冒險\n");
                break;
            case 6:
                printf("負責/奉獻\n");
                break;
            case 7:
                printf("分析/真理\n");
                break;
            case 8:
                printf("邏輯/智力\n");
                break;
            case 9:
                printf("想像/人道\n");
                break;
            }

        }
    }

    printf("\n空缺數表示自己比較欠缺以下這方面的能力:\n");
    for(i=1;i<10;i++)
    {
        if(intCount[i]==0)
        {
            printf("%d:\t",i);
            switch(i)
            {
            case 1:
                printf("創新/獨立\n");
                break;
            case 2:
                printf("平和/直覺\n");
                break;
            case 3:
                printf("理想/美感\n");
                break;
            case 4:
                printf("安全/秩序\n");
                break;
            case 5:
                printf("自由/冒險\n");
                break;
            case 6:
                printf("負責/奉獻\n");
                break;
            case 7:
                printf("分析/真理\n");
                break;
            case 8:
                printf("邏輯/智力\n");
                break;
            case 9:
                printf("想像/人道\n");
                break;
            }
        }
    }

    printf("\n以下是圈圈連線分析：\n");
    printf("你在1-2-3連線連線分析\n");
    if((intCount[1]>0)&&(intCount[2]>0)&&(intCount[3]>0))
    {
        printf("\t對美學習事務相當敏銳。\n");
    }
    else
    {
        if((intCount[1]==0))
        {
            printf("\t缺1者：較沒自信、獨立性不夠、懦弱。\n");
        }
        if((intCount[2]==0))
        {
            printf("\t缺2者：任何東西都想學，但容易遇到內心障礙、瓶頸。\n");
        }
        if((intCount[3]==0))
        {
            printf("\t缺3者：學習很快，但不夠堅持，容易半途而廢、學而不精。\n");
        }

    }
    printf("你在4-5-6連線連線分析\n");
    if((intCount[4]>0)&&(intCount[5]>0)&&(intCount[6]>0))
    {
        printf("\t邏輯組織強，做事條理分明、井然有序。\n");
    }
    else
    {
        if((intCount[4]==0))
        {
            printf("\t缺4者：膽子較小、害怕改變且情緒起伏較大。\n");
        }
        if((intCount[5]==0))
        {
            printf("\t缺5者：缺乏執行力、動力。\n");
        }
        if((intCount[6]==0))
        {
            printf("\t缺6者：不善與人互動。\n");
        }
        if((intCount[4]==0)&&(intCount[5]==0))
        {
            printf("\t缺45者：膽子小、大小事情自己嚇自己。\n");
        }
        if((intCount[5]==0)&&(intCount[6]==0))
        {
            printf("\t缺56者：有時不知如何與人相處，外表冷漠，內心波濤洶湧。\n");
        }
        if((intCount[4]==0)&&(intCount[5]==0)&&(intCount[6]==0))
        {
            printf("\t456全缺者：把所有事情放在心理隱藏、容易讓人感覺陰沉。\n");
        }
    }

    printf("你在7-8-9連線連線分析\n");
    if((intCount[7]>0)&&(intCount[8]>0)&&(intCount[9]>0))
    {
        printf("\t有貴人幫助，有計劃、企圖心、智慧又有人脈，成就大事業是絕對的。\n");
    }
    else
    {
        if((intCount[7]==0))
        {
            printf("\t缺7者：容易壓力大\n");
        }
        if((intCount[8]==0))
        {
            printf("\t缺8者：當主管或經營事業較不求目的，有興趣才是最重要。\n");
        }
        if((intCount[9]==0))
        {
            printf("\t缺9者：若是管理者比較管不動員工。\n");
        }
        if((intCount[7]==0)&&(intCount[8]==0)&&(intCount[9]==0))
        {
            printf("\t789全缺者：成隱性連線，在必要時特質才會顯現，甚至強過顯性連線。\n");
        }
    }

    printf("你在1-4-7連線連線分析\n");
    if((intCount[1]>0)&&(intCount[4]>0)&&(intCount[7]>0))
    {
        printf("\t調錢容易、偏財運佳。\n");
    }
    else
    {
        if((intCount[4]==0))
        {
            printf("\t缺4者：容易因情緒起伏而花錢。\n");
        }
        if((intCount[7]==0))
        {
            printf("\t缺7者：錢容易越花越大筆。\n");
        }
        if((intCount[4]==0)&&(intCount[7]==0))
        {
            printf("\t缺47者：容易吸147連線的財氣。\n");
        }
    }

    printf("你在2-5-8連線連線分析\n");
    if((intCount[2]>0)&&(intCount[5]>0)&&(intCount[8]>0))
    {
        printf("\t活潑、能很快與人打成一片，善交際公關。\n\t擁有此連線又有6：容易有濫桃花氣場。\n");
    }
    else
    {
        if((intCount[2]==0))
        {
            printf("\t缺2者：內心話不易傾訴。\n");
        }
        if((intCount[5]==0))
        {
            printf("\t缺5者：不夠熱情、賺的錢容易往外花、守不住財庫。\n");
        }
        if((intCount[8]==0))
        {
            printf("\t缺8者：熱情公關不會使人怠到壓力及現實 (天生的業務員)。\n");
        }
        if((intCount[2]==0)&&(intCount[5]==0)&&(intCount[8]==0))
        {
            printf("\t258全缺者：在人群中表現較為安靜，但非常有人緣。\n");
        }
    }

    printf("你在3-6-9連線連線分析\n");
    if((intCount[3]>0)&&(intCount[6]>0)&&(intCount[9]>0))
    {
        printf("\t聰明伶俐、表達力佳，很適合從事講師的工作。\n");
    }
    else
    {
        if((intCount[3]==0))
        {
            printf("\t缺3者：容易被人劫財。\n");
        }
        if((intCount[6]==0))
        {
            printf("\t缺6者：表達慾望低。\n");
        }
        if((intCount[9]==0))
        {
            printf("\t缺9者：做事了草、馬虎。\n");
        }
        if((intCount[3]==0)&&(intCount[6]==0)&&(intCount[9]==0))
        {
            printf("\t缺369者：成隱性連線，在必要時特質才會顯現，甚至強過顯性連線。\n");
        }
    }

    printf("你在1-5-9連線連線分析\n");
    if((intCount[1]>0)&&(intCount[5]>0)&&(intCount[9]>0))
    {
        printf("\t樂在工作、積極努力求上進。\n");
    }
    else
    {
        if((intCount[1]==0))
        {
            printf("\t缺1者：懶惰、懦弱、希望別人來幫助他。\n");
        }
        if((intCount[5]==0))
        {
            printf("\t缺5者：工作執行力低、積極度弱、想多做少。\n");
        }
        if((intCount[9]==0))
        {
            printf("\t缺9者：求知慾望低、無法發揮才能。\n");
        }
        if((intCount[1]==0)&&(intCount[5]==0)&&(intCount[9]==0))
        {
            printf("\t缺159者：成隱性連線者，在必要時，特質才會顯現出來，甚至強過顯性連線。\n");
        }
    }

    printf("你在3-5-7連線連線分析\n");
    if((intCount[3]>0)&&(intCount[5]>0)&&(intCount[7]>0))
    {
        printf("\t深受朋友、老闆、同事喜愛。\n");
    }
    else
    {
        if((intCount[5]==0)&&(intCount[7]==0))
        {
            printf("\t缺57者：受氣包、被人碎碎念。\n");
        }
        if((intCount[3]==0)&&(intCount[5]==0))
        {
            printf("\t缺35者：容易被人碎碎念。\n");
        }
        if((intCount[7]==0))
        {
            printf("\t缺7者：愛碎碎念別人。\n");
        }
        if((intCount[3]==0)&&(intCount[5]==0)&&(intCount[7]==0))
        {
            printf("\t缺357者：成隱性連線的人，必須要相處過後才會深受喜愛。\n");
        }
    }

    printf("你在2-4連線連線分析\n");
    if((intCount[2]>0)&&(intCount[4]>0))
    {
        printf("\t反應快、舉一反三、見機行事。\n");
    }
    else
    {
        if((intCount[2]==0))
        {
            printf("\t缺2者：察言觀色能力較弱、內心才不快樂。\n");
        }
        if((intCount[4]==0))
        {
            printf("\t缺4者：膽子小，情緒起伏大。\n");
        }
        if((intCount[2]==0)&&(intCount[4]==0))
        {
            printf("\t缺24者：成隱性連線，在必要時，特質才會顯現出來，甚至強過顯性連線。\n");
        }
    }

    printf("你在2-6連線連線分析\n");
    if((intCount[2]>0)&&(intCount[6]>0))
    {
        printf("\t熱心助人、好打抱不平。\n");
    }
    else
    {
        if((intCount[2]==0))
        {
            printf("\t缺2者：內心話不易訴說。\n");
        }
        if((intCount[6]==0))
        {
            printf("\t缺6者：表達慾望弱、與人互動頻率少。\n");
        }
        if((intCount[2]==0)&&(intCount[6]==0))
        {
            printf("\t缺26者：成隱性連線，在必要時，特質才會顯現出來，甚至強過顯性連線。\n");
        }
    }

    printf("你在4-8連線連線分析\n");
    if((intCount[4]>0)&&(intCount[8]>0))
    {
        printf("\t工作非常有效率、四平八穩，是會創造最大績效的人。\n");
    }
    else
    {
        if((intCount[4]==0))
        {
            printf("\t缺4者：容易因情緒而流失生意。\n");
        }
        if((intCount[8]==0))
        {
            printf("\t缺8者：做公關或業績，不使人倍感壓力及目的。\n");
        }
        if((intCount[4]==0)&&(intCount[8]==0))
        {
            printf("\t缺48者：成隱性連線，在必要時，特質才會顯現出來，甚至強過顯性連線。\n");
        }
    }

    printf("你在6-8連線連線分析\n");
    if((intCount[6]>0)&&(intCount[8]>0))
    {
        printf("\t樂於幫助顧客、解決問題，完成生意，適合服務業。\n");
    }
    else
    {
        if((intCount[6]==0))
        {
            printf("\t缺6者：表達慾望弱、與人互動頻率少。\n");
        }
        if((intCount[8]==0))
        {
            printf("\t缺8者：與人的互動是不求回報跟目的的。\n");
        }
        if((intCount[6]==0)&&(intCount[8]==0))
        {
            printf("\t缺68者：成隱性連線，在必要時，特質才會顯現出來，甚至強過顯性連線。\n");
        }
    }

    printf("\n以下是依照缺數找出你的幸運色\n");
    for(i=1;i<10;i++)
    {
        if(intCount[i]==0)
        {
            printf("%d 代表\t",i);
            switch(i)
            {
            case 1:
                printf("紅\n");
                break;
            case 2:
                printf("橙\n");
                break;
            case 3:
                printf("黃\n");
                break;
            case 4:
                printf("綠\n");
                break;
            case 5:
                printf("藍\n");
                break;
            case 6:
                printf("靛\n");
                break;
            case 7:
                printf("紫\n");
                break;
            case 8:
                printf("金\n");
                break;
            case 9:
                printf("白\n");
                break;
            }
        }

    }
    printf("\n");

    printf("\n以下是依照你生日數的影響：\n");
    printf("生日數：\t%d\n",intBirthday);
    switch(intBirthday)
    {
    case 1:
        printf("(每月1日、10日、19日、28日出生的人)：天生的老大哥\n");
        break;
    case 2:
        printf("(每月2日、11日、20日、29日出生的人)：浪漫和平的外交家\n");
        break;
    case 3:
        printf("(每月3日、12日、21日、30日出生的人)：多才多藝的開心果\n");
        break;
    case 4:
        printf("(每月4日、13日、22日、31日出生的人)：標準實幹的模範生\n");
        break;
    case 5:
        printf("(每月5日、14日、23日出生的人)：渴望變化的自由精靈\n");
        break;
    case 6:
        printf("(每月6日、15日、24日出生的人)：公平正義的戀家子\n");
        break;
    case 7:
        printf("(每月7日、16日、25日出生的人)：真理至上的心靈師\n");
        break;
    case 8:
        printf("(每月8日、17日、26日出生的人)：成就大業的候選人\n");
        break;
    case 9:
        printf("(每月9日、18日、27日出生的人)：世界大同的好鬥士\n");
        break;
    }

    printf("\n以下是星座VS生命靈數影響：\n");
    switch(intConstellation)
    {
    case 1:
        printf("白羊座 Aries 3.21-4.19 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你是個主觀很強的人，只想著自己想做的事。 \n");
            break;
        case 2:
            printf("生命靈數2的人....你會在意別人看你的眼光，個性比較害羞一點。 \n");
            break;
        case 3:
            printf("生命靈數3的人....喜歡表達自己的想法，但也要多聽聽別人的意見哦！\n");
            break;
        case 4:
            printf("生命靈數4的人....你對未來很關心，很少胡思亂想，會腳踏實地的努力。\n");
            break;
        case 5:
            printf("生命靈數5的人....最愛玩的白羊非你莫屬，尤其喜歡到處去湊熱鬧。\n");
            break;
        case 6:
            printf("生命靈數6的人....你很固執哦！尤其是感情層面，而且非常的主觀。\n");
            break;
        case 7:
            printf("生命靈數7的人....對於自己覺得有理的地方非常的堅持，不聽別人的意見。\n");
            break;
        case 8:
            printf("生命靈數8的人....很重視實際層面的成就，會很努力在學習和工作上。\n");
            break;
        case 9:
            printf("生命靈數9的人....你是較不切實際的人，不過你的熱情可將不可能變可能。\n");
            break;
        }
        break;
    case 2:
        printf("金牛座 Taurus 4.20-5.20\n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你的行動力很強，對事自有一套，做法也不喜歡受干涉。 \n");
            break;
        case 2:
            printf("生命靈數2的人....你會重視人際關係，在與別人相處時也比較容易受影響。\n");
            break;
        case 3:
            printf("生命靈數3的人....你是牛座中比較靈活的，喜歡發表自己所研究出來的事物。\n");
            break;
        case 4:
            printf("生命靈數4的人....你是牛座中最固執的哦！你的想法常常和別人不太一樣。\n");
            break;
        case 5:
            printf("生命靈數5的人....你是一隻多才多藝的牛，如果能夠定下來會更有成就。\n");
            break;
        case 6:
            printf("生命靈數6的人....你是最念舊的牛座，對於自己重視的東西會非常呵護。\n");
            break;
        case 7:
            printf("生命靈數7的人....你是有叛逆性格的牛牛，不易被別人說服，自有一套想法。\n");
            break;
        case 8:
            printf("生命靈數8的人....你很重視實際層面的成就，會努力讓自己更加的優秀或成功。\n");
            break;
        case 9:
            printf("生命靈數9的人....你是牛座中最有夢想的，但是要多學習如何落實在現實中。\n");
            break;
        }
        break;
    case 3:
        printf("雙子座 Gemini 5.21-6.21 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....喜歡自由自在的你，對於自己有興趣的事情都會去鑽研哦！ \n");
            break;
        case 2:
            printf("生命靈數2的人....你是最喜歡與別人溝通的雙子座，不過很容易受外來的影響。 \n");
            break;
        case 3:
            printf("生命靈數3的人....你真的是雙子座中最為多才多藝的，什麼東西都是一學就會。\n");
            break;
        case 4:
            printf("生命靈數4的人....你是比較重視生活規律的人，看來隨和但自有一套規則。\n");
            break;
        case 5:
            printf("生命靈數5的人....喜歡到處亂跑的你真是交友滿天下，心性上也比較不穩定。\n");
            break;
        case 6:
            printf("生命靈數6的人....你是雙子中最重視人情味的，尤其重視老朋友之間的感情。\n");
            break;
        case 7:
            printf("生命靈數7的人....你是雙子中最刁鑽古怪的，常想些別人都不會想到的問題。\n");
            break;
        case 8:
            printf("生命靈數8的人....你喜歡享受生活，會特別的注重自己的生活品質。\n");
            break;
        case 9:
            printf("生命靈數9的人....你是雙子中最會胡思亂想的，同時也是比較熱情的。\n");
            break;
        }
        break;
    case 4:
        printf("巨蟹座 Cancer 6.22-7.22 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你個性上有點自閉哦！不容易真正和別人有好的交流。 \n");
            break;
        case 2:
            printf("生命靈數2的人....會很看重別人的意見，要小心因此喪失自己的意見。\n");
            break;
        case 3:
            printf("生命靈數3的人....喜歡感情上的表達與溝通，在藝術上會有不錯的天份哩！\n");
            break;
        case 4:
            printf("生命靈數4的人....你是蟹子中比較龜毛的，尤其重視自己生活上的規律。\n");
            break;
        case 5:
            printf("生命靈數5的人....你不一定喜歡亂跑，但不能受到太多拘束，想自由自在。\n");
            break;
        case 6:
            printf("生命靈數6的人....你是蟹座中最重感情的，尤其在感情世界裡很要求完美。\n");
            break;
        case 7:
            printf("生命靈數7的人....你是蟹子中想得最多的，表現出來的模樣也頗為固執己見。\n");
            break;
        case 8:
            printf("生命靈數8的人....你很重視現實上的成就與穩定，會努力讓自己的生活更好。\n");
            break;
        case 9:
            printf("生命靈數9的人....你是蟹子中相當熱情的，但剛到新的環境會比較害羞。\n");
            break;
        }
        break;
    case 5:
        printf("獅子座 Leo 7.23-8.22 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你是獅子座中最為自我的，但可能因此造成人際問題。 \n");
            break;
        case 2:
            printf("生命靈數2的人....別人的肯定對你來說非常重要，可能因此而失去自我。\n");
            break;
        case 3:
            printf("生命靈數3的人....你是獅子座中最愛表現自己的，通常是人際關係中的佼佼者。\n");
            break;
        case 4:
            printf("生命靈數4的人....你是隻固執的獅子，而且在行動上比較缺乏冒險犯難的精神。\n");
            break;
        case 5:
            printf("生命靈數5的人....獅子中最熱愛自由的就是你啦！一般來說你們是相當大方的。\n");
            break;
        case 6:
            printf("生命靈數6的人....你是獅子座中比較龜毛的，尤其是感情的表達上會顯得害羞。\n");
            break;
        case 7:
            printf("生命靈數7的人....你是很會想的獅子座哦！雖然比較主觀，但還可以溝通。\n");
            break;
        case 8:
            printf("生命靈數8的人....你是一個講究生活品味的人哦！喜歡從容優渥的過日子。\n");
            break;
        case 9:
            printf("生命靈數9的人....你的熱情很容易感動別人，在人群中常是人氣很旺的明星哩！\n");
            break;
        }
        break;
    case 6:
        printf("處女座 Virgo 8.23-9.22 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你有點孤僻，常常覺得別人不了解你，要多與別人互動才好。 \n");
            break;
        case 2:
            printf("生命靈數2的人....你會很注重每個人的意見，與別人來往時也是非常誠懇的。 \n");
            break;
        case 3:
            printf("生命靈數3的人....能力頗佳的你，適合擔任發言或主持的任務，會勝任愉快哦！\n");
            break;
        case 4:
            printf("生命靈數4的人....你是處女座中最為龜毛的，尤其容易劃地自限，要特別注意。\n");
            break;
        case 5:
            printf("生命靈數5的人....你是屬於比較外向的，容易交到許多朋友，但知心的並不多。\n");
            break;
        case 6:
            printf("生命靈數6的人....你是非常非常念舊的人哦！尤其是感情上，常常很難割捨。\n");
            break;
        case 7:
            printf("生命靈數7的人....你的個性比較剛直，不過在與人交往上還是要多體諒別人哦！\n");
            break;
        case 8:
            printf("生命靈數8的人....你是比較圓滑的人，很了解人際上的交流要如何互動。\n");
            break;
        case 9:
            printf("生命靈數9的人....對你投入的事情非常的狂熱，有時甚至因此而廢寢忘食。\n");
            break;
        }
        break;
    case 7:
        printf("天秤座 Libra 9.23-10.22 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你是秤子中比較獨立的，在決定事情時也比較不會猶豫不決。\n");
            break;
        case 2:
            printf("生命靈數2的人....在秤子中你是最需要別人陪伴的，如果沒有伴會感到不安。\n");
            break;
        case 3:
            printf("生命靈數3的人....你是秤子中最有才華的，在各項藝術領域都有不錯的天份。\n");
            break;
        case 4:
            printf("生命靈數4的人....你是秤子中最為重視實際層面的，也是比較有責任感的哦！\n");
            break;
        case 5:
            printf("生命靈數5的人....你是一隻喜愛交遊的天秤，對感到好玩的事情都不會放過。\n");
            break;
        case 6:
            printf("生命靈數6的人....感情的順利與否對你來說非常重要哦！要小心的經營才好。\n");
            break;
        case 7:
            printf("生命靈數7的人....你是秤子中最喜歡思考的，對許多事都會找出合理的方法。\n");
            break;
        case 8:
            printf("生命靈數8的人....很重視生活的感覺，不能忍受太差的生活環境，有雅癖傾向。\n");
            break;
        case 9:
            printf("生命靈數9的人....你許多想法都有些不切實際，而且熱情常常無法持久哦！\n");
            break;
        }
        break;
    case 8:
        printf("天蠍座 Scorpio 10.23-11.21 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你很重視自己的目標，不太理睬身邊其他人在做些什麼。\n");
            break;
        case 2:
            printf("生命靈數2的人....你很在乎兩人關係上的忠誠，會全心全意的對待另一半。\n");
            break;
        case 3:
            printf("生命靈數3的人....對於溝通與人際關係是你的專長，總能夠得到大家幫助。\n");
            break;
        case 4:
            printf("生命靈數4的人....你是非常非常固執的，一旦你決定的事就難以改變。\n");
            break;
        case 5:
            printf("生命靈數5的人....你是蠍子中最開朗的，也是最容易與大家打成一片的。\n");
            break;
        case 6:
            printf("生命靈數6的人....你是個完美主義者，尤其是非常重視感情方面的經營。\n");
            break;
        case 7:
            printf("生命靈數7的人....你想的很多，常想到一些別人找不到的問題，非常聰明。\n");
            break;
        case 8:
            printf("生命靈數8的人....你很重視自己的地社會地位，認為應該得到的就會去爭取。\n");
            break;
        case 9:
            printf("生命靈數9的人....對於你喜歡或相信的事是非常狂熱的，但表面上看不出來。 \n");
            break;
        }
        break;
    case 9:
        printf("射手座 Sagittarius 11.22-12.21 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你常常我行我素，一有目標就會很快去執行，行動力很強。\n");
            break;
        case 2:
            printf("生命靈數2的人....喜歡與別人溝通相處的你，在人際上會得到大家的幫忙。\n");
            break;
        case 3:
            printf("生命靈數3的人....你是相當有才華的人哦！很能夠表現自己在藝術上的才華。\n");
            break;
        case 4:
            printf("生命靈數4的人....你是射手座中最重視生活規律的，而且也很有自己的想法。\n");
            break;
        case 5:
            printf("生命靈數5的人....哇！你真是超愛亂跑，一直待在同一個地方會讓你很難過。\n");
            break;
        case 6:
            printf("生命靈數6的人....你是很重視親情的人哦！在人際交流上也是很有一套的。\n");
            break;
        case 7:
            printf("生命靈數7的人....你真是想得太多，又有點固執的人，懷疑的心態很強哦！\n");
            break;
        case 8:
            printf("生命靈數8的人....你很重視自己的成就和外在的表現，喜歡富裕的生活環境。\n");
            break;
        case 9:
            printf("生命靈數9的人....你是很有理想的人，也是舉辦活動的高手，受到大家歡迎！\n");
            break;
        }
        break;
    case 10:
        printf("摩羯座 Capricorn 12.22-1.19\n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你的自尊心很強哦！會默默的努力讓自己有所成就。\n");
            break;
        case 2:
            printf("生命靈數2的人....你覺得與人交遊是件重要的事，另外感情也是生活重心。 \n");
            break;
        case 3:
            printf("生命靈數3的人....只要你多加努力就能展現出自己的才華，會很有成就哦！\n");
            break;
        case 4:
            printf("生命靈數4的人....你很重視腳踏實地的生活，會努力讓自己生活穩定下來。\n");
            break;
        case 5:
            printf("生命靈數5的人....你是摩羯座中比較開朗的，對一些事比較不會那麼憂慮。\n");
            break;
        case 6:
            printf("生命靈數6的人....感情是你生活平穩的重點，希望經營有未來的感情生活。\n");
            break;
        case 7:
            printf("生命靈數7的人....你是一個非常聰明的人，但有時會因情緒化而下錯判斷。\n");
            break;
        case 8:
            printf("生命靈數8的人....對你來說功成名就吸引力大，會努力成為重要的人物。\n");
            break;
        case 9:
            printf("生命靈數9的人....你對自己想做的事非常投入，不過有時會忘了實際狀況。\n");
            break;
        }
        break;
    case 11:
        printf("水瓶座 Aquarius 1.20-2.18 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你是瓶子座中最自閉的，有時候會顯得太過我行我素了些。 \n");
            break;
        case 2:
            printf("生命靈數2的人....你會比較受到別人的影響，但還不會失去自己原本的主張。\n");
            break;
        case 3:
            printf("生命靈數3的人....你是一隻多才多藝的瓶子哩！尤其擅長於表達與溝通哦！\n");
            break;
        case 4:
            printf("生命靈數4的人....你是瓶子中比較穩定的，會習慣維持某一種生活的方式。\n");
            break;
        case 5:
            printf("生命靈數5的人....常常讓人找不到的就是你這種瓶子啦！朋友也是多不勝數。\n");
            break;
        case 6:
            printf("生命靈數6的人....你是比較重感情的瓶子，也比較桃花，感情問題會比較多。\n");
            break;
        case 7:
            printf("生命靈數7的人....你是瓶子中最為理性的，太過聰明的話有時候會不近人情。\n");
            break;
        case 8:
            printf("生命靈數8的人....你是瓶子中比較重視物質的，會去追求自己所想要的生活。\n");
            break;
        case 9:
            printf("生命靈數9的人....你的理想非常高遠，如果持續努力，成功的機會是很大的。\n");
            break;
        }
        break;
    case 12:
        printf("雙魚座 Pieces 2.19-3.20 \n");
        switch(intMain)
        {
        case 1:
            printf("生命靈數1的人....你容易沈溺在自己的世界的，忘掉了身邊還有別人存在。\n");
            break;
        case 2:
            printf("生命靈數2的人....你很容易受到別人的引導，而忘記了自己原本的方向哦！\n");
            break;
        case 3:
            printf("生命靈數3的人....你是天生的藝術家，不過還是要稍為注意一下現實環境。\n");
            break;
        case 4:
            printf("生命靈數4的人....你是追求穩定生活的魚座，不喜歡太過混亂的生活。\n");
            break;
        case 5:
            printf("生命靈數5的人....你比較沒有目標，幾乎什麼事都會去做做看，但都維持不久。\n");
            break;
        case 6:
            printf("生命靈數6的人....感情是你最煩惱的事，常常因此而受到打擊或挫折。\n");
            break;
        case 7:
            printf("生命靈數7的人....你想得很多，但是一旦遇到自己的事情就會比較主觀。\n");
            break;
        case 8:
            printf("生命靈數8的人....你是喜歡享受的魚座，對於生活上的小事都非常的注意。\n");
            break;
        case 9:
            printf("生命靈數9的人....你對於某些事都抱著很大的熱誠，過度的話會顯得特別偏執。\n");
            break;
        }
        break;
    }
    return 0;
}
