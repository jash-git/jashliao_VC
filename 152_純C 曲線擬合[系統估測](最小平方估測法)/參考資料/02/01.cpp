//Exponential Fit
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int i,j,k,n;
    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays
    cin>>n;
    double x[n],y[n],lny[n],a,b,c;
    cout<<"\nEnter the x-axis values:\n";                //Input x-values(observed)
    for (i=0;i<n;i++)
        cin>>x[i];
    cout<<"\nEnter the y-axis values:\n";                //Input y-values(observed)
    for (i=0;i<n;i++)
        cin>>y[i];
    for (i=0;i<n;i++)                        //Calculate the values of ln(yi)
        lny[i]=log(y[i]);        
    double xsum=0,x2sum=0,ysum=0,xysum=0;                //variables for sums/sigma of xi,yi,xi^2,xiyi etc
    for (i=0;i<n;i++)
    {
        xsum=xsum+x[i];                        //calculate sigma(xi)
        ysum=ysum+lny[i];                        //calculate sigma(yi)
        x2sum=x2sum+pow(x[i],2);                //calculate sigma(x^2i)
        xysum=xysum+x[i]*lny[i];                    //calculate sigma(xi*yi)
    }
    a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);            //calculate slope(or the the power of exp)
    b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);            //calculate intercept
    c=pow(2.71828,b);                        //since b=ln(c)
    double y_fit[n];                        //an array to store the new fitted values of y    
    for (i=0;i<n;i++)
        y_fit[i]=c*pow(2.71828,a*x[i]);                    //to calculate y(fitted) at given x points
    cout<<"S.no"<<setw(5)<<"x"<<setw(19)<<"y(observed)"<<setw(19)<<"y(fitted)"<<endl;
    cout<<"-----------------------------------------------------------------\n";
    for (i=0;i<n;i++)
        cout<<i+1<<"."<<setw(8)<<x[i]<<setw(15)<<y[i]<<setw(18)<<y_fit[i]<<endl;//print a table of x,y(obs.) and y(fit.)    
    cout<<"\nThe corresponding line is of the form:\n\nlny = "<<a<<"x + ln"<<b<<endl;
    cout<<"\nThe exponential fit is given by:\ny = "<<c<<"e^"<<a<<"x\n";
    return 0;
}   