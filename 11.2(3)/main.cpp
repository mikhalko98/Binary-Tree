#include <iostream>
#include <cstring>
#include <cmath>
#include<fstream>
#include<string>
    using namespace std;
    ofstream fout;
    ifstream fin;
         int i;
         int const n=7;
    struct car{
        int nomber;
        char id[20];
        char marka[20];
        char model[20];
        int year;
        char color[20];
        int price;
        char registration_number[20];
              };
    struct node{
          car key;
          node *left, *right;
            };


        void scan (car *inf,const char *fname );
        bool addElement( car value, node **pNode);
        void traverseTree(node *pNode);
       // node *findElement(car key, node *pNode);
        void registration_number(node *pNode,char registration_number1[]);
        void scanEl(car *inf);
        void removeElement(int value, node **pNode);
        void removeEl(node **pNode, node **q);
        void savetoFile(node *pNode, const char *fname);
int main()
{
     car *inf=new car[n];
     scan (inf, "data.txt");
     node *tree = NULL;
     for(i=0;i<n;i++){
      addElement(inf[i],&tree);
     }
     traverseTree(tree);
            int pr=0;
           char registration_number1[20];
            cout<<"Enter registration number: ";
            cin>>registration_number1;
     registration_number(tree, registration_number1);
            cout<<"__Enter the data___"<<endl;
     scanEl(inf);
            addElement(inf[n],&tree);
          traverseTree(tree);

            int el3;
            cout<<"Delete element #:";
            cin>>el3;
            removeElement(el3,&tree);
            traverseTree(tree);

        int prov;
    cout<<"Save to file:  0-NO"<<'\t'<<"1-YES"<<endl;
    cout<<"               ";
    cin>>prov;
    if(prov=1){
                fout.open("rezult.txt");
            savetoFile(tree, "rezult.txt");
    cout<<endl;
    cout<<"Rezult in file";}
return 0;
}
    void scan (car *inf,const char *fname){
            ifstream fin("data.txt");
            for(i=0;i<n;i++){
        fin>>inf[i].nomber;
        fin>>inf[i].id;
        fin>>inf[i].marka;
        fin>>inf[i].model;
        fin>>inf[i].year;
        fin>>inf[i].color;
        fin>>inf[i].price;
        fin>>inf[i].registration_number;}
}

    bool addElement( car value, node **pNode){
        if(*pNode == NULL){
            node *t = new node;
            t->key = value;
            t->left = t->right = NULL;
            *pNode = t;
            return true;
        }
        else {
                car key = (*pNode)->key;
            if(key.nomber == value.nomber) return false;
            if(key.nomber > value.nomber){
                return addElement(value, &((*pNode)->left));
            }
            else return addElement(value,&((*pNode)->right));
        }

    }
    void traverseTree(node *pNode){
            if(pNode != NULL){
              traverseTree(pNode->left);
              cout<<"___Car #___:"<<pNode->key.nomber<<endl;
              cout<<"Id: "<<pNode->key.id<<endl;
              cout<<"Brend: "<<pNode->key.marka<<endl;
              cout<<"Model: "<<pNode->key.model<<endl;
              cout<<"Year:  "<<pNode->key.year<<endl;
              cout<<"Color: "<<pNode->key.color<<endl;
              cout<<"Price: "<<pNode->key.price<<endl;
              cout<<"Registration_number:"<<pNode->key.registration_number<<endl;
              traverseTree(pNode->right);
            }
    }
    node *findElement(car key, node *pNode){
            if(pNode == NULL){
                return NULL;
            }
            if(pNode->key.nomber == key.nomber)
                return pNode;

            return findElement(key, (pNode->key.nomber > key.nomber)
                                        ? pNode->left
                                        : pNode->right);}


        void registration_number(node *pNode, char registration_number1[]){
            if(pNode != NULL){
                registration_number(pNode->left,registration_number1);
                    if( !stricmp(pNode->key.registration_number, registration_number1)){
              cout<<"___Car #___:"<<pNode->key.nomber<<endl;
              cout<<"Id: "<<pNode->key.id<<endl;
              cout<<"Brend: "<<pNode->key.marka<<endl;
              cout<<"Model: "<<pNode->key.model<<endl;
              cout<<"Year:  "<<pNode->key.year<<endl;
              cout<<"Color: "<<pNode->key.color<<endl;
              cout<<"Price: "<<pNode->key.price<<endl;
              cout<<"Registration_number:"<<pNode->key.registration_number<<endl;}
              registration_number(pNode->right, registration_number1);
            }
            }

                 void scanEl(car *inf){
                     inf[n].nomber=n+1;
                 cout<<"___Car #___:"<<inf[n].nomber<<endl;
        cout<<"Enter id: ";
        cin>>inf[n].id;
        cout<<"Enter brend: ";
        cin>>inf[n].marka;
        cout<<"Enter model: ";
        cin>>inf[n].model;
        cout<<"Enter year:  ";
        cin>>inf[n].year;
        cout<<"Enter color: ";
        cin>>inf[n].color;
        cout<<"Enter price: ";
        cin>>inf[n].price;
        cout<<"Enter registration_number:";
        cin>>inf[n].registration_number;
cout<<endl<<endl;
                 }
                 void removeElement(int value, node **pNode){
                        if(*pNode == NULL);
                        else{
                            if(value < (*pNode)->key.nomber)
                                removeElement(value,&((*pNode)->left));
                                else{
                                    if(value > (*pNode)->key.nomber )
                                      removeElement(value,&((*pNode)->right));
                                    else{
                                        node *q = *pNode;
                                        if(q->left == NULL) *pNode = q->left;
                                        else if(q->left == NULL) *pNode = q->right;
                                        else{removeEl(&(q->left), &q); }
                                    delete q;}
                                }
                        }
                 }
        void removeEl(node **pNode, node **q){
            if((*pNode)->right != NULL) removeEl(&(*pNode)->right,q);
            else{
                (*q)->key = (*pNode)->key;
                *q = *pNode;
                *pNode = (*pNode)->left;
            }
        }
     void savetoFile(node *pNode, const char *fname){
        if(pNode != NULL){
           savetoFile(pNode->left, "rezult.txt");
            fout<<"___Car #___:"<<pNode->key.nomber<<endl;
              fout<<"Id: "<<pNode->key.id<<endl;
              fout<<"Brend: "<<pNode->key.marka<<endl;
              fout<<"Model: "<<pNode->key.model<<endl;
              fout<<"Year:  "<<pNode->key.year<<endl;
              fout<<"Color: "<<pNode->key.color<<endl;
              fout<<"Price: "<<pNode->key.price<<endl;
              fout<<"Registration_number:"<<pNode->key.registration_number<<endl;
              savetoFile(pNode->right, "rezult.txt");
        }

    }
