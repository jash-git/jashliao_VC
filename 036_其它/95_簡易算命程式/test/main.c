#include <stdio.h>
#include <stdlib.h>
static int yearw(int y)
{
	int a = 0;
	y = (y - 12) % 60;
	switch (y)
	{
		case 1: a = 12; break;
		case 2: a = 9; break;
		case 3: a = 6; break;
		case 4: a = 7; break;
		case 5: a = 12; break;
		case 6: a = 5; break;
		case 7: a = 9; break;
		case 8: a = 8; break;
		case 9: a = 7; break;
		case 10: a = 8; break;
		case 11: a = 15; break;
		case 12: a = 9; break;
		case 13: a = 16; break;
		case 14: a = 8; break;
		case 15: a = 8; break;
		case 16: a = 19; break;
		case 17: a = 12; break;
		case 18: a = 6; break;
		case 19: a = 8; break;
		case 20: a = 7; break;
		case 21: a = 5; break;
		case 22: a = 15; break;
		case 23: a = 6; break;
		case 24: a = 16; break;
		case 25: a = 15; break;
		case 26: a = 7; break;
		case 27: a = 9; break;
		case 28: a = 12; break;
		case 29: a = 10; break;
		case 30: a = 7; break;
		case 31: a = 15; break;
		case 32: a = 6; break;
		case 33: a = 5; break;
		case 34: a = 14; break;
		case 35: a = 14; break;
		case 36: a = 9; break;
		case 37: a = 7; break;
		case 38: a = 7; break;
		case 39: a = 9; break;
		case 40: a = 12; break;
		case 41: a = 8; break;
		case 42: a = 7; break;
		case 43: a = 13; break;
		case 44: a = 5; break;
		case 45: a = 14; break;
		case 46: a = 5; break;
		case 47: a = 9; break;
		case 48: a = 17; break;
		case 49: a = 5; break;
		case 50: a = 7; break;
		case 51: a = 12; break;
		case 52: a = 8; break;
		case 53: a = 8; break;
		case 54: a = 6; break;
		case 55: a = 19; break;
		case 56: a = 6; break;
		case 57: a = 8; break;
		case 58: a = 16; break;
		case 59: a = 10; break;
		case 60: a = 7; break;
	}
    return (a);
}
static int monthw(int x)
{
	int y=0;
	switch (x)
	{
		case 1: y = 6; break;
		case 2: y = 7; break;
		case 3: y = 18; break;
		case 4: y = 9; break;
		case 5: y = 5; break;
		case 6: y = 16; break;
		case 7: y = 9; break;
		case 8: y = 15; break;
		case 9: y = 18; break;
		case 10: y = 8; break;
		case 11: y = 9; break;
		case 12: y = 5; break;

	}
	return (y);

}
static int timew(int a)
{
	int b=0;
	switch (a)
	{
		case 1: b = 16; break;
		case 2: b = 6; break;
		case 3: b = 7; break;
		case 4: b = 10; break;
		case 5: b = 9; break;
		case 6: b = 16; break;
		case 7: b = 10; break;
		case 8: b = 8; break;
		case 9: b = 8; break;
		case 10: b = 9; break;
		case 11: b = 6; break;
		case 12: b = 6; break;

	}
	return (b);

}
static int dayw(int j)
{
	int dayw=0;
	switch (j)
	{
		case 1: dayw=5; break;
		case 2: dayw=10; break;
		case 3: dayw=8; break;
		case 4: dayw=15; break;
		case 5: dayw=16; break;
		case 6: dayw=15; break;
		case 7: dayw=8 ; break;
		case 8: dayw=16; break;
		case 9: dayw=8; break;
		case 10: dayw=16; break;
		case 11: dayw=9; break;
		case 12: dayw=17; break;
		case 13: dayw=8; break;
		case 14: dayw=17; break;
		case 15: dayw=10; break;
		case 16: dayw=8; break;
		case 17: dayw=9; break;
		case 18: dayw=18; break;
		case 19: dayw=5; break;
		case 20: dayw=15; break;
		case 21: dayw=10; break;
		case 22: dayw=9; break;
		case 23: dayw=8; break;
		case 24: dayw=9; break;
		case 25: dayw=15; break;
		case 26: dayw=18; break;
		case 27: dayw=7; break;
		case 28: dayw=8; break;
		case 29: dayw=16; break;
		case 30: dayw=6; break;
	}
	return (dayw);
}
static void fatecomments(int total)
{
	printf("您的命格重 %d 兩 %d 錢:\n", total/10,total%10);
	switch(total)
	{
		case 21:
			printf("衣食奔波出外手藝之人\n");
			printf("短命非業謂大凶 平生災難事重重 凶禍頰臨陷逆境 終世困苦事不成\n");
			break;
		case 22:
			printf("幼年勞碌中年清泰之人\n");
			printf("身寒骨冷苦伶仃 此命推來行乞人 碌碌巴巴無度日 終年打拱過平生\n");
			break;
		case 23:
			printf("先難後易出外救人之命\n");
			printf("此命推來骨自輕 求謀作事事難成 妻兒兄弟應難許 別處他鄉作散人\n");
			break;
		case 24:
			printf("人智巧多能出家求食之人\n");
			printf("此命推來福祿無 門庭困苦總難翁 六親骨肉皆無靠 流到他鄉作老榮\n");
			break;
		case 25:
			printf("身閒心不閒九流藝術之人\n");
			printf("此命推來祖業微 門庭營度以稀奇 六親骨肉如冰炭 一世勤勞自把持\n");
			break;
		case 26:
			printf("幹辦營運先貧後富勞碌之人\n");
			printf("平生衣祿苦中求 獨自營謀事不休 離祖出門宜早計 晚來衣祿自無憂\n");
			break;
		case 27:
			printf("超群出眾聰明進貴衣祿之人\n");
			printf("一生作靠少商量 難靠祖宗作主張 獨馬單鎗空做去 早年晚歲總無長\n");
			break;
		case 28:
			printf("自卓為人才能近貴之人\n");
			printf("一生作事似飄蓬 祖宗產業在夢中 若不過房併改姓 也相移徒二三通\n");
			break;
		case 29:
			printf("才能客商守權達變智慧之人\n");
			printf("初年運限未曾享 縱有功名在後成 需過四旬才可上 移居改姓始為良\n");
			break;
		case 30:
			printf("衣食有餘獨自卓立成家之命\n");
			printf("勞勞碌碌苦中求 東走西奔何日休 若始終身勤與儉 老來稍可免憂愁\n");
			break;
		case 31:
			printf("先貧後富近貴藝術衣食足用之人\n");
			printf("忙忙碌碌苦中求 難得祖基家可立 何日雲開見日預 中年衣食漸無憂\n");
			break;
		case 32:
			printf("性巧過人百事精衣食到老近貴之人\n");
			printf("初年運寒事難謀 漸有財源如水流 到得中年衣食旺 那時名利一齊來\n");
			break;
		case 33:
			printf("衣食豐滿富貴巧藝術智之人\n");
			printf("易年做事事難成 百計從勞枉費心 半世自如流水去 後來運到得黃金\n");
			break;
		case 34:
			printf("財榖有餘主得內助爵祿富貴之人\n");
			printf("此命福氣果如何 僧道門中衣祿多 離祖出家方得妙 終朝拜佛念彌陀\n");
			break;
		case 35:
			printf("有福祿先難後易過房入贅近富之人\n");
			printf("生平福星不周全 祖業根基覺少傳 營事生涯宜守舊 時來衣食勝從前\n");
			break;
		case 36:
			printf("超群拔類乖巧智慧衣祿厚重之人\n");
			printf("不須勞祿過平生 獨自成家福不輕 早有福星常照命 任君行去百般成\n");
			break;
		case 37:
			printf("聰明富貴才能厚重有福壽之人\n");
			printf("此命般般事不成 弟兄少力自孤成 雖然祖業須微有 來得明去時得明\n");
			break;
		case 38:
			printf("財帛豐厚宜稱之人\n");
			printf("一生骨肉最清高 早入黌門姓名標 待看年將三十六 藍衫脫去換紅袍\n");
			break;
		case 39:
			printf("利上近貴有福有祿之人\n");
			printf("此命終身運不窮 勞勞作事盡皆空 苦心竭力成家計 到得那時在夢中\n");
			break;
		case 40:
			printf("富貴近益生涯鼎盛機關之命\n");
			printf("平生衣祿是綿長 件件心中自主張 前面風霜多受過 後來必定享安康\n");
			break;
		case 41:
			printf("稅戶近貴專才為人衣祿之人\n");
			printf("此命推來事不同 為人能幹異凡庸 中年還有逍遙福 不比前年運未通\n");
			break;
		case 42:
			printf("兵權有職富貴才能之人\n");
			printf("得寬懷處且寬懷 何用隻眉趨不開 若使中年命運濟 那時名利一齊來\n");
			break;
		case 43:
			printf("財碌厚重白手成家之人\n");
			printf("為人心性最聰明 作事軒昂近貴人 衣祿一生天數定 不須勞碌是豐亨\n");
			break;
		case 44:
			printf("好學近貴巧智財祿富厚之人\n");
			printf("來事由天莫苦求 須知福祿勝前途 當年財帛難如意 晚景欣然便不憂\n");
			break;
		case 45:
			printf("福祿豐厚極富且貴之人\n");
			printf("名利推來竟若無 前途辛苦後奔波 命中難養男與女 骨肉扶持也不多\n");
			break;
		case 46:
			printf("富貴有餘福壽雙全之命\n");
			printf("東西南北盡皆道 出姓移名更覺隆 衣祿無虧天數定 中年晚景一般同\n");
			break;
		case 47:
			printf("高官祿厚學業飽滿之人\n");
			printf("此命推來旺未年 妻榮子貴自怡然 平生原有滔滔禍 可有財源如水源\n");
			break;
		case 48:
			printf("官員財祿厚重之人\n");
			printf("幼年運道夫曾亨 若是蹉跎再不與 兄弟六親皆無靠 一身事業晚年成\n");
			break;
		case 49:
			printf("性巧精神倉庫財祿之命\n");
			printf("此命推來福不輕 自成自立顧門庭 從來富貴人親近 使婢差奴過一生\n");
			break;
		case 50:
			printf("文武才能錢榖豐盛之人\n");
			printf("為利為名終日勞 中年福祿也多遭 老來是有財星照 不比前番目下高\n");
			break;
		case 51:
			printf("祿厚官職財祿榮華富貴之命\n");
			printf("一世榮華事事通 不須勞碌自亨通 弟兄叔姪皆如意 家業成時福祿宏\n");
			break;
		case 52:
			printf("掌握兵權富貴長壽之人\n");
			printf("一世亨通事事能 不須勞思自然能 宗族欣然心皆好 家業豐亨自稱心\n");
			break;
		case 53:
			printf("青衣貴人僧道門中近貴之人 \n");
			printf("此格推來氣象真 興家發達在其中 一生福祿安排定 卻是人間一富翁\n");
			break;
		case 54:
			printf("有勇有謀威權富貴財祿之命\n");
			printf("此命推來厚且清 詩書滿腹看功成 豐衣足食自然穩 正是人間有福人\n");
			break;
		case 55:
			printf("八品官職財祿豐盛之人\n");
			printf("走馬楊邊爭利名 少年做事費籌論 一朝福祿源源至 富貴榮華顯六親\n");
			break;
		case 56:
			printf("七品官職長享榮華富貴\n");
			printf("此格推來禮義通 一生福祿用無盡 甜酸苦辣皆嚐盡 財源滾滾穩且豐\n");
			break;
		case 57:
			printf("六品官職文章壓眾精通之人\n");
			printf("福祿盈盈萬事全 一生榮耀顯雙親 名揚威振人欽敬 處世逍遙似遇春\n");
			break;
		case 58:
			printf("官祿旺相才能性直富貴之人\n");
			printf("生平福祿自然來 名利兼全福壽偕 雁塔提名為貴客 紫袍金帶走金\n");
			break;
		case 59:
			printf("五品官職財祿厚重之人\n");
			printf("細推此格妙且清 必定財高禮義通 甲第之中應有分 揚鞭走馬顯威勞\n");
			break;
		case 60:
			printf("四品官職榮華福壽財祿之人\n");
			printf("一朝金榜快提名 顯祖榮宗立大動 衣食定然原裕足 田園財帛更豐盈\n");
			break;
		case 61:
			printf("法身官掌風雷權柄之人\n");
			printf("不作朝中金榜克 定為世上一財翁 聰明天付經書熟 明顯高科目是榮\n");
			break;
		case 62:
			printf("三品官職有權柄之人\n");
			printf("此命生來福不窮 讀書必定顯親榮 紫夜金帶來卿相 富貴榮華皆可同\n");
			break;
		case 63:
			printf("指揮太守萬戶封侯之命\n");
			printf("命主為官福祿長 得來福貴為非常 命題金塔傳金長 定中高科天下揚\n");
			break;
		case 64:
			printf("二品官職尚書郎之命\n");
			printf("此格威權不可當 紫袍金帶坐高堂 榮華富貴誰人及 積玉堆金滿儲倉\n");
			break;
		case 65:
			printf("掌楬權威極大齊福祿之人\n");
			printf("細推此命福不輕 定國安邦極品人 文繡雕樑微富貴 威聲照耀四方聞\n");
			break;
		case 66:
			printf("公侯駙馬丕相之命\n");
			printf("此格人間一福人 堆金積玉滿堂春 從來富貴由天定 正笏垂神謁聖君\n");
			break;
		case 67:
			printf("英名冠世萬國來朝之人\n");
			printf("此命生來福自宏 田園家業最高隆 平生衣祿豐盈足 一生榮華萬事通\n");
			break;
		case 68:
			printf("溫和富貴繁榮極吉之命\n");
			printf("富貴由天不須求 萬金家計自然豐 十年不比前番事 祖業根基水上舟\n");
			break;
		case 69:
			printf("惠收高位功名顯達之命\n");
			printf("君是人間衣祿星 一生富貴眾人欽 安然福祿由天定 安享榮華過一生\n");
			break;
		case 70:
			printf("權力具備極品上流之命\n");
			printf("此命推來福不輕 不須愁慮苦勞心 一生天定衣祿興 富貴榮華主一生\n");
			break;
		case 71:
			printf("此乃大志大業勢如破竹之命也\n");
			printf("此命生來大不同 公侯將相在其中 一生自有逍遙福 富貴榮華海品隆\n");
			break;
		case 72:
			printf("此乃罕有生帝王之命也\n");
			printf("恭喜你中樂透!!\n");
			break;
		default: break;

	}
}
static int chinese_animal(int w)
{

	w = (w < 0) ? w + 1 : w;
	w = w % 12;
	w = (w <= 0) ? w + 12 : w;
	//因為餘數為0，所以沒有這行的話，餘數為0出不來


	return (w);
}
static void output(int y)
{
	switch (y)
	{
		case 1: printf("生肖:鼠\n"); break;
		case 2: printf("生肖:牛\n"); break;
		case 3: printf("生肖:虎\n"); break;
		case 4: printf("生肖:兔\n"); break;
		case 5: printf("生肖:龍\n"); break;
		case 6: printf("生肖:蛇\n"); break;
		case 7: printf("生肖:馬\n"); break;
		case 8: printf("生肖:羊\n"); break;
		case 9: printf("生肖:猴\n"); break;
		case 10: printf("生肖:雞\n"); break;
		case 11: printf("生肖:狗\n"); break;
		case 12: printf("生肖:豬\n"); break;
	}
}
int main()
{
    int y=0,m=0,d=0,t=0;
	int yw, mw, dw, tw, total;
    printf("Hello world!\n");
	printf("輸入生年(民國):\n");
	scanf("%d",&y);
	printf("輸入生月(舊曆):\n");
	scanf("%d",&m);
	printf("輸入生日(舊曆):\n");
	scanf("%d",&d);
	printf("輸入生時(24時):\n");
	scanf("%d",&t);
	yw = yearw(y);   //生年兩數
	mw = monthw(m);  //生月兩數
	dw = dayw(d);  //生日兩數
	tw = timew(t);  //生辰兩數
	total = yw+mw+dw+tw;
	output(chinese_animal(y));
	fatecomments(total);  //總兩數和評語
    return 0;
}
