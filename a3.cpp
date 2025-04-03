//assignment-3 of flight path
#include<iostream>
using namespace std;
class matrix{
    public:
    int m[100][100];
    matrix()
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                m[i][j]=0;
            }
        }
    }

    void edge(int x,int y,int z)
    {
        m[x][y]=z;
        m[y][x]=z;
    }
};
class list{
    public:
    string data;
    int dis;
    list *next;

    list(string x,int y)
    {
        data=x;
        dis=y;
        next=NULL;
    }
    list(){

    }
    void insert(list *&head,list *temp)
    {
        
        if(head==NULL)
        {
            head=temp;
        }else{
            list *current=head;
            while(current->next!=NULL)
            {
                current = current->next;
            }
            current->next=temp;
        }
    }
    void display(list *current)
    {
        if(current==NULL)
        {
            return;
        }
        while(current!=NULL)
        {
            cout<<current->data<<"("<<current->dis<<")  ";
            current=current->next;
        }
    }
};
int main()
{
    matrix am;
    int ch,City=0,edges,no,c1,c2,dist;
    string arr[20],v1,v2,d;
    list *hed[20],*temp;
    list l;
    do{
        cout<<"\n1.Adjancancy matrix\t2.Output(AM)\t3.Adjacency list\t4.Output(AL)\t5.Insert new city\t6.Exit\nEnter choice :";
        cin>>ch;
        switch(ch)
        {
            case 1://input 
                    cout<<"Enter no.of Cities:";
                    cin>>City;
                    for(int i=0;i<City;i++)
                    {
                        cout<<"City-"<<i+1<<":";
                        cin>>arr[i];
                    }
                    cout<<"Enter no.of edges:";
                    cin>>edges;
                    for(int i=0;i<edges;i++)
                    {
                        cout<<"edge-"<<i+1<<endl;
                        cout<<"\tCity-1 :";
                        cin>>v1;
                        cout<<"\tCity-2 :";
                        cin>>v2;
                        cout<<"Enter distance between them :";
                        cin>>dist;
                        for(int k=0;k<City;k++)
                        {
                            if(v1==arr[k])
                            {
                                c1=k;
                            }
                            if(v2==arr[k])
                            {
                                c2=k;
                            }
                        }
                        
                        am.edge(c1,c2,dist);
                    }
                    break;
            case 2://output of AM
                   for(int i=0;i<City;i++)
                   {
                    cout<<"\t"<<arr[i];
                   }
                   cout<<"\n\n\n";
                   for(int i=0;i<City;i++)
                   {
                    cout<<arr[i]<<"\t";
                    for(int j=0;j<City;j++)
                    {
                        cout<<am.m[i][j]<<"\t";
                    }
                    cout<<"\n\n";
                   }
                   break;
            case 3://adjacency list
                   cout<<"Enter no.of Cities :";
                   cin>>City;
                   cout<<"Enter Cities :"<<endl;
                   for(int i=0;i<City;i++)
                   {
                    cout<<"City-"<<i+1<<": ";
                    cin>>arr[i];
                   }
                   for(int i=0;i<City;i++)
                   {
                    hed[i]=NULL;
                    cout<<"Enter no.of adjacent Cities for City-"<<arr[i]<<" :";
                    cin>>no;
                    for(int j=0;j<no;j++)
                    {
                        cout<<"City-"<<j+1<<" :";
                        cin>>d;
                        cout<<"Enter distance of city-"<<d<<" from city-"<<arr[i]<<": ";
                        cin>>dist;
                        temp=new list(d,dist);
                        if(hed[i]==NULL)
                        {
                            hed[i]=temp;
                        }else{
                        l.insert(hed[i],temp);
                        }
                    }
                   
                   }
                 break;

            case 4://display
                   for(int i=0;i<City;i++)
                   {
                    cout<<arr[i]<<"-->";
                    l.display(hed[i]);
                    cout<<endl;
                   }
                   break;

           case 5://insert new city in existing graph
                  cout<<"Enter city name:";
                  cin>>d;
                  cout<<"Enter city name which linked this city :";
                  cin>>v1;
                  cout<<"Enter distance between them :";
                  cin>>dist;
                  if(City==0)
                  {
                    cout<<"Graph NOT exist !";
                  }
                  for(int i=0;i<City;i++)
                  {
                    if(arr[i]==v1)
                    {
                        c2=i;
                        break;
                    }
                  }
                  arr[City]=d;
                  am.edge(c2,City,dist);
                  City++;
                  break;

        }
    }while(ch!=6);
}
