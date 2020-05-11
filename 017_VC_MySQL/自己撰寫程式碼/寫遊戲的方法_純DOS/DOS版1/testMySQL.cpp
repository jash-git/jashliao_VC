#include <iostream>
#include <iomanip>
#include <mysql++>

int main() {
  // The full format for the Connection constructor is
  // Connection(cchar *db, cchar *host="", 
  //            cchar *user="", cchar *passwd="") 
  // You may need to specify some of them if the database is not on
  // the local machine or you database username is not the same as your
  // login name, etc..
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
			cout<<setw(6)<<row["id"]
				<<setw(15)<<row["data1"]
				<<setw(10)<<row["data2"]
				<<setw(10)<<row["data3"]<<endl;
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
