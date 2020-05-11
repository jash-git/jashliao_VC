#include <iostream>
#include <iomanip>
#include <mysql++>
#include <stdio.h>

int main() {
  // The full format for the Connection constructor is
  // Connection(cchar *db, cchar *host="", 
  //            cchar *user="", cchar *passwd="") 
  // You may need to specify some of them if the database is not on
  // the local machine or you database username is not the same as your
  // login name, etc..
	int id,data2,data3;
	string data1;
	FILE *fp;
	fp=fopen("database.txt","w");
  try {
		//由於MySQL安裝好之後預設帳號為root，密碼為空白
		//ps當登錄127.0.0.1可以不用IP，帳號
		//Connection con("chtvdata");
		//Connection con("chtvdata","127.0.0.1");
		//Connection con("chtvdata","127.0.0.1","root");
		Connection con("chtvdata","192.168.12.63","root");
///*
		Query query = con.query();
		// This creates a query object that is bound to con.

		query << "select * from chtvtable";
		// You can write to the query object like you would any other ostrem

		Result res = query.store();
		// Query::store() executes the query and returns the results
		Result ::iterator i;
		Row row;
		for(i=res.begin();i!=res.end();i++)
		{
			row=*i;
			id=row["id"];
			data1=row["data1"];
			data2=row["data2"];
			data3=row["data3"];
			cout<<setw(6)<<id
				<<setw(15)<<data1
				<<setw(10)<<data2
				<<setw(10)<<data3<<endl;
			    string s = "Hello";
			//printf("%s", s.c_str());
			char *data11;
			data11=(char *)data1.c_str(); 
			fprintf(fp,"%d\t%s\t%d\t%d\n",id,data11,data2,data3);
			
		}
//*/
  } catch (BadQuery er){ // handle any connection 
                         // or query errors that may come up
    cerr << "Error: " << er.error <<  endl;
    return -1;

  } catch (BadConversion er) {
    // we still need to cache bad conversions incase something goes 
    // wrong when the data is converted into stock
    cerr << "Error: Tried to convert \"" << er.data << "\" to a \""
	 << er.type_name << "\"." << endl;
    return -1;
  }
	return 0;
}
