#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class record
{
    int height;
    int i;
    int r;
    int c;
    int s;
    int *integer;
    float *real;
    char **str;
    char *character;
    public:
    int record_sno;
    record *left;
    record *right;
    record()
    {
        left=right=NULL;
        i=c=s=r=0;
    }
    void enterdata(char*,char);
    void showdata();
};

class table
{
        public:
        int sizer;
        int sizei;
        int sizec;
        int sizes;
        int table_sno;
        string tablename;
        string type;
        vector<string> col;
        //AVL_tree data_stored_as_tree;
        table()
        {
            ;
        }
        table(int w,int x,int y,int z,char a[],char b[],vector<string>c)
        {
            sizei=w;
            sizes=x;
            sizer=y;
            sizec=z;
            tablename=a;
            type=b;
            vector<string>col(c);
            table_sno=0;
        }
};

/*class AVL_tree
{
    record *root;
    public:
    AVL_tree()
    {
        root=NULL;
    }
    record* newNode(record);
    record* insertnode();
    void display();
    record* deletenode();
    record* left_rotate();
    record* right_rotate();
    int height();
    int getbalance(record);
    int maximum(int,int)
};*/

int return_equivalent(char[]);
bool check_schema(char[],char[]);
int stringlength(char[],int,char);
void stringclip(char[],char[],int,char,int&);
table searchtable_and_return(char*);
bool searchtable_for_existence(char*);
void createcommand_for_createtable(char*);
void insertcommand(char*);
void displaycommand(char*);
void dropcommand(char*);

list<table> tablist;

int main()
{
    int i;
    char *str;
    char *temp;
    str=new char;
    temp=new char;
    cout<<"Sequel Server.";
    cout<<"\nIllustration of Data Structures, Algorithms and Data anticipating procedures.";
    cout<<"\nNo Data is being stored!";
    cout<<"\nTables stored in STL lists, records as nodes of AVL trees.";
    cout<<"\nMade by Sayan, Dheeraj, Ayush, Udit, JIIT 62.";
    cout<<"\n->Type command 'Help' to open instructions\n";
    cout<<"---------------------------------------------------------------------------------------";
    do{
        cout<<"\nSeql->";
        gets(str);
        stringclip(str,temp,0,' ',i);
        cout<<"    ->Recognized Command.";
        if(strcmpi(temp,"CreateTable")==0)
        {
            createcommand_for_createtable(str);
        }
        else if(strcmpi(temp,"InsertInto")==0)
        {
            insertcommand(str);
        }
        else if(strcmpi(str,"DeleteRecord")==0)//l
        {
            deletecommand(str);
        }
        else if(strcmp(str,"DisplayTable")==0)//l
         {
             displaycommand(str);
         }
        else if(strcmpi(temp,"DropTable")==0)
        {
            dropcommand(str);
        }
        else if(strcmpi(temp,"Exit")==0)
        {
            cout<<"\n    ->QUERY OK\n";
            break;
        }
        else if(strcmpi(temp,"Help")==0)
        {
            cout<<"    ->This is a Database Language where in you can create simple relational schema and store data in them.\n";
            cout<<"    ->Creation of tables:\n    ->\t[CREATETABLE (TABLE_NAME):(DATA TYPE) (ATTRIBUTE NAME),(DATA TYPE) (ATTRIBUTE NAME)....] AS SYNTAX TO CREATE TABLES\n";
            cout<<"    ->Insertion of data:\n    ->\t[DROPTABLE (TABLE NAME)] AS SYNTAX TO DROP A TABLE\n";
            cout<<"    ->YOU CAN USE [EXIT] TO EXIT FROM THIS\n";
        }
        else
        {
            cout<<"\n    ->SYNTAX ERROR,PLEASE CHECK YOUR SYNTAX\n";
        }
    }while(1<2);
    delete str;
    return 0;
}

/*record* AVL_tree::newNode(record r)
{
    Node*node=new Node;
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return(node);
}

int AVL_tree::newNode(int a,int b)
{
    return(a>b)?a:b;
}

int AVL_tree::height(record r)
{
    if(r==NULL)
    {
        return 0;
    }
    return r->height;
}

int AVL_tree::getbalance(record r)
{
    if(r==NULL)
    {
        return 0;
    }
    return height(r->left)-height(r->right);
}

record* AVL_tree::right_rotate(record y)
{
    record x=y->left;
    record T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=maximum(height(y->left),height(y->right))+1;
    x->height=maximum(height(x->left),height(x->right))+1;
    return x;
}

record* AVL_tree::left_rotate(record x)
{
    record y=x->right;
    record T2=y->left;
    y->left=x;
    x->right=T2;
    x>height=maximum(height(x->left),height(x->right))+1;
    y->height=maximum(height(y->left),height(y->right))+1;
    return y;
}

record* AVL_tree::insertnode(record *node, record r)
{
    if (node == NULL)
    {
        return(newNode());
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }
    node->depth = 1 + max(depth(node->left),  depth(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

record* Avl_tree::deletenode(record* root, record r)
{
    if(root==NULL)
    {
        return  root;
    }
    if(key<root->key)
    {
        root->left=deletenode(root->left,key);
    }
    else if(key>root->key)
    {
        root->right=deletenode(root->right,key);
    }
    else
    {
        if((root->left == NULL)||(root->right == NULL))
        {
            record temp = root->left ? root->left:root->right;
            if(temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else
            {
                root=temp;
                free(temp);
            }
        }
        else
        {
            record temp = min_value_node(root->right);
            root->key=temp->key;
            root->right=deletenode(root->right,temp->key);
        }
    }
    if(root==NULL)
    {
        return root;
    }
    root->height=1+maximum(height(root->left),height(root->right));
    int balance=getbalance(root);
    if(balance>1 && getbalance(root->left)>=0)
    {
        return right_rotate(root);
    }
    if(balance>1 && getbalance(root->left)<0)
    {
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance<-1 && getbalance(root->right)<=0)
    {
        return left_rotate(root);
    }
    if(balance<-1 && getbalance(root->right>0))
    {
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}*/

int return_equivalent(char str[])
{
    int L=strlen(str),i,counter=0;
    for(i=0;i<L;++i)
    {
        counter+=(str[i]-48)*pow(10,(L-i-1));
    }
    return counter;
}

int stringlength(char str[],int pos,char delimiter)
{
    int count=0;
    int i=pos;
    while(str[i]!=delimiter&&str[i]!=';')
    {
        count++;
        ++i;
    }
    return count+1;
}

void stringclip(char str[],char temp_str[],int pos,char delimiter,int &i)
{
    int j=0;
    i=pos;
    while(str[i]!=delimiter && str[i]!=';')
    {
        temp_str[j++]=str[i++];
    }
    temp_str[j]='\0';
}

/*void record::enterdata(char *term,char ch,char type='m')
{
   int L=strlen(term)-1,g=0;
   if(ch=='c' && term[L]==34)
   {
       character[c++]=term[1];
   }
   else if(ch=='s' && term[L]==39)
   {
       term=stringclip(term,1,'"',g);
       strcpy(str[s++],term);
   }
   else if(ch=='x' && isdigit(term[L]) && type=='r')
   {
       real[r]=0.0;
       int pos,k;
       bool flag=false;
       for(k=0;term[k]!='\0';++k)
       {
           if(term[k]=='.')
           {
               real[i]=0;
               pos=k;
               flag=true;
               break;
           }
           real[i]+=term[k]*pow(10,L+1-k);
       }
       if(flag)
       {
           for(k=pos-1;k>=0;--k)
           {
               real[r]+=term[k]*pow(10,pos-k-1);
           }
           for(k=pos+1;k<=L;++k)
           {
               real[r]+=term[k]*pow(0.1,k-pos-1);
           }
       }
   }
   else if(ch=='x'&& isdigit(term[L])&&type=='d')
   {
       integer[i]=0;
       int k;
       bool flag=false;
       for(k=0;term[k]!='\0';++k)
       {
           if(term[k]=='.')
           {
               integer[i]=0;
               flag=true;
               break;
           }
           integer[i]+=term[k]*pow(10,L+1-k);
       }
       if(flag)
       {
           cout<<"\nError. The data does not matches table definition.";
       }
   }
   else
   {
       cout<<"\nError. The data does not matches table definition.";
   }
}*/

table searchtable_and_return(char *name)
{
    list<table>::iterator itr,i1=tablist.begin();
    table temp;
    for (itr = tablist.begin(); itr != tablist.end(); ++itr)
    {
        if(itr->tablename==name)
        {
            std::iter_swap(itr,i1);
            temp=tablist.front();
            tablist.pop_front();
            return temp;
        }
    }
    temp.tablename="thisnodefault";
    return temp;
}

bool searchtable_for_existence(char name[])
{
    list<table>::iterator itr,i1=tablist.begin();
    table temp;
    for (itr = tablist.begin(); itr != tablist.end(); ++itr)
    {
        if(itr->tablename==name)
        {
            return true;
        }
    }
    return false;
}

void createcommand_for_createtable(char str[])
{
    int i=0,j=0,sizer,sizei,sizec,sizes,L;
    bool check;
    vector<string> col;
    L=stringlength(str,12,' ');
    char tablename[L];
    stringclip(str,tablename,12,' ',i);
    L=stringlength(str,i+1,':');
    char cardinality[L];
    stringclip(str,cardinality,i+1,':',i);
    L=return_equivalent(cardinality);
    char type[L];
    check=searchtable_for_existence(tablename);
    if(check)
    {
        cout<<"\n    ->Error. The table name provided already exists.";
        return;
    }
    while(str[i]!=';')
    {
        L=stringlength(str,i+1,' ');
        char datatype[L];
        stringclip(str,datatype,i+1,' ',i);
        if(strcmpi(datatype,"integer")==0)
        {
            sizei++;
            type[j]='d';
        }
        else if(strcmpi(datatype,"real")==0)
        {
            sizer++;
            type[j]='r';
        }
        else if(strcmpi(datatype,"character")==0)
        {
            sizec++;
            type[j]='c';
        }
        else if(strcmpi(datatype,"str")==0)
        {
            sizes++;
            type[j]='s';
        }
        else
        {
            cout<<"\n    ->ERROR: UNDEFINED IDENTIFIER. PLEASE CHECK YOUR SYNTAX\n";
            return;
        }
        L=stringlength(str,i+1,',');
        char attribute[L];
        stringclip(str,attribute,i+1,',',i);
        col.push_back(attribute);
        j++;
    }
    type[j]='\0';
    cout<<"\n    ->Table "<<tablename<<" is read!";
    tablist.push_back(table(sizei,sizes,sizer,sizec,tablename,type,col));
    cout<<"\n    ->Table saved to memory.";
    cout<<"\n    ->Query Ok.\n";
}

void insertcommand(char str[])
{
    table temp;
    record r;
    int i=0,j=0;
    int L;
    bool check;
    L=stringlength(str,11,':');
    char tablename[L];
    stringclip(str,tablename,11,':',i);
    check=searchtable_for_existence(tablename);
    if(!check)
    {
        cout<<"\n    ->ERROR: QUERIED TABLE NOT FOUND!.\n";
        return;
    }
    else
    {
        temp=searchtable_and_return(tablename);
        while(str[i]!=';')
        {
            L=stringlength(str,i+1,',');
            char ch[L];
            stringclip(str,ch,i+1,',',i);
            if(ch[0]==39 && temp.type[j++]=='s')//39 ASCII of "
            {
                r.enterdata(ch,'s');
            }
            else if(ch[0]==34 && temp.type[j++]=='c')//34 ASCII of '
            {
                r.enterdata(ch,'c');
            }
            else if(temp.type[j]=='r' || temp.type[j]=='d')
            {
                r.enterdata(ch,temp.type[j]);
                ++j;
            }
            else
            {
                cout<<"\n    ->ERROR: TABLE SCHEMA MISMATCHED.\n";
                return;
            }
        }
        r.record_sno=temp.table_sno+1;
        temp.table_sno+=1;
    }
    tablist.push_back(temp);
    cout<<"\nQUERY OK.";
}

bool check_schema(char tablename[],char str[])
{
    int i=0,L;
    bool check;
    table temp=searchtable_and_return(tablename);
    while(str[i]!=';')
    {
        L=stringlength(str,8+strlen(tablename),',');
        char ch[L];
        stringclip(str,ch,i+1,',',i);
        //find(temp.col.begin(), temp.col.end(),ch) != temp.col.end())?check=true:check=false;
           // return check;
    }
    return check;
}

void displaycommand(char str[])
{
    int i=0,L=stringlength(str,8,':');
    char tablename[L];
    stringclip(str,tablename,8,':',i);
    L=stringlength(str,i+1,':');
    char tableschema[L];
    stringclip(str,tableschema,i+1,';',i);
    if(check_schema(tablename,tableschema))
    {
        table T;
        T=searchtable_and_return(tablename);
        //T.tree.display_inorder(tableschema);
    }
    else
    {
        cout<<"\n    ->ERROR: TABLE SCHEMA MISMATCHED.";
    }
}

void dropcommand(char *str)
{
    int i=0;
    int L;
    L=stringlength(str,10,' ');
    char tabname[L];
    stringclip(str,tabname,10,' ',i);
    list<table>::iterator itr;
    for (itr = tablist.begin(); itr != tablist.end(); ++itr)
    {
        if(itr->tablename==tabname)
        {
            tablist.erase(itr);
            cout<<"\n";
            return;
        }
    }
    cout<<"\n    ->ERROR: QUERIED TABLE DOES NOT EXIST..";
}

void record::enterdata(char values[],char type)
{
    int index=0,L;
    L=strlen(values);
    if(type=='s')
    {
        char val[L-2];
        stringclip(values,val,1,39,index);
        str[s]=val;
        s++;
    }
    else if(type=='c')
    {
        character[c]=values[1];
        c++;
    }
    else if(type=='d')
    {
        integer[i]=return_equivalent(values);
        i++;
    }
    else if(type=='r')
    {
        bool found=false;
        int characteristic=0,mantissa=0;
        characteristic=return_equivalent(values);
        mantissa=return_equivalent(values);
        real[r]=characteristic+mantissa;
        r++;
    }
    else
    {
        cout<<"\n    ->ERROR: CHECK THE VALUES YOU ENTERED";
    }
}
