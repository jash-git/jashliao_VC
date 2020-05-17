#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"
using namespace std;
void printNode(TiXmlNode* node);
int main()
{
    cout << "Hello world!" << endl;
	TiXmlDocument doc("test_jash.xml");
	doc.LoadFile();
	TiXmlNode *root = doc.RootElement();
	printNode(root);
    return 0;
}
void printNode(TiXmlNode* node) //迴圈列印所有的節點
{
	if(node == NULL) return;
		cout<<"["<<node->Value()<<"]"<<endl; //顯示節點的名稱
	TiXmlElement* element = node->ToElement();

	if(element && element->GetText()) //顯示節點的內容
           	cout<<"      -->"<< element->GetText()<<endl;

	if(element && element->FirstAttribute()) //顯示節點屬性
	{
		TiXmlAttribute *IDAttribute = element->FirstAttribute();
		while ( IDAttribute )
		{
			cout<<"      -->"<<"Attribute name="<<IDAttribute->Name()<<"\t";
			cout<<"       ::"<< IDAttribute->Value() << endl;
			IDAttribute=IDAttribute->Next();
		}
	}

	TiXmlElement* child = node->FirstChildElement();
	while(child!=NULL)
	{
		printNode(child); //遞迴調用顯示節點
		child = child->NextSiblingElement();
	}
}
