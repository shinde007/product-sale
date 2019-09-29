#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class Product
{ private:
   int id;
   char name[30];
   long rate;
   int stock;
  public:
    void getProduct()
    { cout<<"Enter Id:";cin>>id;
      cout<<"Enter Name:";cin>>name;
      cout<<"Enter Rate:";cin>>rate;
      cout<<"Enter Stock:";cin>>stock;
    }
    void putProduct()
     { cout<<"   "<<id<<"   ,    "<<name<<"    ,    "<<rate<<"    ,    "<<stock<<endl;
      }

  void sale()
  {int qty;
   cout<<"Enter Quantity U Want to Sale:";
   cin>>qty;
   if(stock>=qty)
    {long amt=rate*qty;
     cout<<"Total Amount:"<<amt<<endl;
     stock=stock-qty;
     }
     else if(stock==0)
     {
     	cout<<"Out Of Stock";
     }
     else
     {cout<<"Less Qty..."<<endl;}
	  }

 void purchase()
   {int qty;
    cout<<"Enter Quantity U Want to Purchase:";
    cin>>qty;
    stock=stock+qty;
    cout<<"Stock Updated..."<<endl;
 }


 int searchById(int);
    int searchByName(char*);
	};
int Product::searchById(int pid)
   {if(pid==id)
     {cout<<"Product ID   "<<"Product Name   "<<"Product  Rate   "<<"Product Stock   "<<endl;
	 putProduct();
       return(1);
      }
      return(0);
   }

int Product::searchByName(char *n)
   {if(strcmpi(name,n)==0)
     {cout<<"Product ID   "<<"Product Name   "<<"Product  Rate   "<<"Product Stock   "<<endl;
	 putProduct();
       return(1);
      }
      return(0);
   }

int main()
{	int t;
	cout<<"enter no. of products";
	cin>>t;
	Product P[t];
 
 for(int i=0;i<=t-1;i++)
  {P[i].getProduct();}
  int ch,i,pid,found=0;
  int count=0;
  char n[30];
  do{
    cout<<"Main Menu\n1] Display All Products\n2] Serach By Id\n3] Search By Name\n4] Sale\n5] Purchase\n6] Exit\n";
    cout<<"Ur Choice?";
    cin>>ch;
    switch(ch)
    {case 1:
    	cout<<"Product ID   "<<"Product Name   "<<"Product  Rate   "<<"Product Stock   "<<endl;
       for(i=0;i<=2;i++)
       {P[i].putProduct();}
       break;
     case 2:
       cout<<"Enter Product Id:";
       cin>>pid;
        for(i=0;i<=2;i++)
       { found=P[i].searchById(pid);
         if(found){break;}
       }
       if(!found)
       {cout<<"Product Not Exist.."<<pid<<endl;}
       break;
     case 3:
       
       cout<<"Enter Product Name U Want to Search:";
       cin>>n;
        for(i=0;i<=2;i++)
       { found=P[i].searchByName(n);
		 if(found){count++;}
       }
       if(count==0)
       {cout<<"Product Not Exist.."<<n<<endl;}
       else
       {cout<<"Total Product Found:"<<count<<endl;}
       break;
       
	 case 4:
       cout<<"Enter Product Id U Want to Sale:";
	          cin>>pid;
	           for(i=0;i<=2;i++)
	          { found=P[i].searchById(pid);
	            if(found){
					P[i].sale();
					break;}
	          }
	          if(!found)
	          {cout<<"Product Not Exist.."<<pid<<endl;}
	          break;

     case 5:
	         cout<<"Enter Product Id U Want to Purchase:";
	  	          cin>>pid;
	  	           for(i=0;i<=2;i++)
	  	          { found=P[i].searchById(pid);
	  	            if(found){
	  					P[i].purchase();
	  					break;}
	  	          }
	  	          if(!found)
	  	          {cout<<"Product Not Exist.."<<pid<<endl;}
	          break;
      case 6:
         cout<<"Good Bye"<<endl;
         break;
      default:
         cout<<"Wrong Option.."<<endl;

    }
    cout<<"Press Any Key to Cont.."<<endl;
}while(ch!=6);


     }








