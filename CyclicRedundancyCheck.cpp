#include<iostream>
#include<process.h>
using namespace std;
int main()
{	
		
		char ch='y';
		int ctr;
		int i,j,k,l,flag=0;
		int data[20],divisor[20],code[40],temp[30],crc[30],rem[20],datalen,divlen,codelen;
	do
	{	
		cout<<"\n ------OPTIONS------ \n 1. CRC GENERATOR \n 2. CRC CHECKER \n 3. EXIT ";
		cout<<"\n ENTER YOUR CHOICE : ";
		cin>>ctr;
		switch(ctr)
		{
			case 1 : cout<<"\n ENTER DATAWORD LENGTH : ";
    				 cin>>datalen;
    				 cout<<"\n ENTER DATA BITS :";
					 for(i=0;i<datalen;i++)
					    {
					        cin>>data[i];
					    }
					 cout<<"\n ENTER DIVISOR LENGTH : ";
    				 cin>>divlen;
    				 cout<<"\n ENTER DIVISOR BITS :";
					 for(i=0;i<divlen;i++)
					    {
					        cin>>divisor[i];
					    }
					 codelen = divlen - 1;
					 cout<<"\n NUMBER OF 0's TO BE APPENDED : "<<codelen;
					 for (i=datalen;i<datalen+codelen;i++)
					 {
				         data[i]=0;
				     }
				     for(i=0;i<20;i++)
					 {
					      temp[i]=data[i];
					 }
					 cout<<"\n CODE AFTER APPENDING 0's :";
					 for(i=0; i<datalen+codelen;i++)
					 {
					        cout<<temp[i];
					 }
					 for(i=0;i<datalen;i++)
				     {
				        j=0;
				        k=i;
				        if (temp[k]>=divisor[j])
				        {
				            for(j=0,k=i;j<divlen;j++,k++)
				            {
				                if((temp[k]==1 && divisor[j]==1) || (temp[k]==0 && divisor[j]==0))
				                {  temp[k]=0;	}
				                else
				                {  temp[k]=1;	}
				            }
				        }
				     }
				     for(i=0,j=datalen;i<codelen;i++,j++)
				     { crc[i]=temp[j];	}
				 	 cout<<"\n CRC BITS : ";
				     for(i=0;i<codelen;i++)
				     { cout<<crc[i]; }
				         cout<<"\n \n  TRANSMITTED CODE BITS : \t ";
					    for(i=0;i<datalen;i++)
					    {
					        code[i]=data[i];
					    }
					    for(i=datalen,j=0;i<datalen+codelen;i++,j++)
					    {
					        code[i]=crc[j];
					    }
					    for(i=0;i<datalen+codelen;i++)
					    {
					        cout<<code[i];
					    }
					    break;
			
			case 2 : cout<<"\n ENTER RECEIVED DATAWORD LENGTH : ";
    				 cin>>datalen;
    				 cout<<"\n ENTER DATA BITS :";
					 for(i=0;i<datalen;i++)
					    {
					        cin>>data[i];
					    }
					 cout<<"\n ENTER DIVISOR LENGTH : ";
    				 cin>>divlen;
    				 cout<<"\n ENTER DIVISOR BITS :";
					 for(i=0;i<divlen;i++)
					    {
					        cin>>divisor[i];
					    }
					 codelen = divlen - 1;
				     for(i=0;i<codelen+datalen;i++)
				     { temp[i]=code[i];	}
				    for(i=0;i<codelen+datalen;i++)
				    {
				        j=0;
				        k=i;
				        if (temp[k]>=divisor[j])
				        {
				            for(j=0,k=i;j<divlen;j++,k++)
				            {
				                if((temp[k]==1 && divisor[j]==1) || (temp[k]==0 && divisor[j]==0))
				                {
				                    temp[k]=0;
				                }
				                else
				                {
				                    temp[k]=1;
				                }
				            }
				        }
				    }
				        cout<<"\n REMAINDER : ";
					    for (i=datalen,j=0;i<codelen+datalen;i++,j++)
					    {
					        rem[j]= temp[i];
					    }
					    for(i=0;i<codelen;i++)
					    {
					        cout<<rem[i];
					    }
					 
					    flag=0;
					    for(i=0;i<codelen;i++)
					    {
					        if(rem[i]!=0)
					        {
					            flag=1;
					        }
					    }
					 
					    if(flag==0)
					    {
					        cout<<"\n TRANSMISSION SUCCESSFUL";
					    }
					    else
					    {
					        cout<<"\n TRANSMISSION UNSUCCESSFUL !!!!   DISCARDING DATA ";
					    }
					    break;
			case 3 : exit(0);
			default : cout<<"WRONG CHOICE !!!";						 
		}
	cout<<"\n WANT TO CONTINUE ? (Y/N) : ";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}
