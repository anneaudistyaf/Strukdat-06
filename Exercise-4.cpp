/*
NAMA PROGRAM : EXERCISE 4
NAMA 		 : ANNE AUDISTYA FERNANDA
NPM			 : 140810180059
KELAS		 : A
TANGGAL 	 : 15 APRIL 2019
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct contact{
	char nama[20];
	char nomor[12];
	contact* nextcontact;
};
struct index{
	char info[5];
	contact* FirstContact;
	index* next;
};
typedef index* pointerIndex;
typedef contact* pointerContact;
typedef pointerIndex list;

void createListIndex(list& First){
	First=NULL;
}

void createElmtIndex(pointerIndex& pBaru){
	pBaru= new index;
	cout<<"Masukan Index :"; cin>>pBaru->info;
	pBaru->next=NULL;
	pBaru->FirstContact=NULL;
}

void createElmtContact(pointerContact& pBaru){
	pBaru= new contact;
	cout<<"Masukan Nama   :"; cin>>pBaru->nama;
	cout<<"Masukan Nomor  :"; cin>>pBaru->nomor;
	pBaru->nextcontact=NULL;
}

void traversalIndex(list First){
	pointerIndex pBantu;
	pBantu=First;
	cout<<"Index :"<<endl;
	while(pBantu!=NULL){
		cout<<"|- "<<pBantu->info<<endl;
		pBantu=pBantu->next;
	}
}

void linearSearch(list First,char key[20],int& status,pointerIndex& pCari){
	status=0;
	pCari=First;
	while(status==0 && pCari!=NULL){
		if(strcmp(pCari->info,key)==0){
			status=1;
		}
		else{
			pCari=pCari->next;
		}
	}
}

void insertFirstIndex(list& First,pointerIndex pBaru){
	if(First==NULL){
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void deleteFirstIndex(list& First,pointerIndex pHapus){
	if(First==NULL){
  		cout<<"tidak ada yang dihapus "<<endl;
 	}
	else if(First->next==NULL){
  		pHapus=First;
		First=NULL;
 	}
	else{
  		pHapus=First;
  		First=pHapus->next;
  		First->next=NULL;
 	}
}

void insertFirstContact(list& First,char key[20],pointerContact pBaru){
	pointerIndex pInd;
 	int ketemu;
 	cout<<"Masukan Index yang di cari: "; cin>>key;
 	linearSearch(First,key,ketemu,pInd);
 	if(ketemu){
  		cout<<"Ditemukan dengan Index :"<<pInd->info<<endl;
  		if(pInd->FirstContact==NULL){
   			pInd->FirstContact=pBaru;
  		}
  	else{
   		pBaru->nextcontact=pInd->FirstContact;
   		pInd->FirstContact=pBaru;
  	}
 	}
	else{
  		cout<<"Nama Index tidak di temukan"<<endl;
 	}
}

void deleteFirstContact(list& First,char key[5],pointerContact& pHapus ){
	int ketemu;
	pointerIndex pIn;
	cout<<"Masukan Index yang di cari: "; cin>>key;
	linearSearch(First,key,ketemu,pIn);
		if(ketemu){
		cout<<"Ditemukan dengan Index :"<<pIn->info;
		if(pIn->FirstContact==NULL){
			cout<<"Tidak ada yang di hapus"<<endl;
		}
		else if(pIn->FirstContact->nextcontact==NULL){
			pHapus=pIn->FirstContact;
			pIn->FirstContact=NULL;
		}
		else{
			pHapus=pIn->FirstContact;
			pIn->FirstContact=pIn->FirstContact->nextcontact;
			pHapus->nextcontact=NULL;
			
		}
	}
	else{
		cout<<"Index tidak di temukan"<<endl;
	}
	
}

void traversalIndContact(list First){
    pointerIndex pBantuInd;
    pointerContact pBantuCon;
    cout<<"Traversal Index"<<endl;
    pBantuInd=First;
    while (pBantuInd!=NULL){
        cout<<"|- "<<pBantuInd->info<<endl;
        pBantuCon=pBantuInd->FirstContact;
        while (pBantuCon!=NULL) {
        	cout<<"\t|- "<<pBantuCon->nama<< " / "<<pBantuCon->nomor<<endl;
        	pBantuCon=pBantuCon->nextcontact;
        }
        pBantuInd=pBantuInd->next;
    }
}

main(){

    list q;
    int nd,nk,pilih;
    char key [20];
    pointerIndex pd,pc,phd;
    pointerContact pk,phk;
    createListIndex(q);
    do{
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1.Insert Index"<<endl;
        cout<<"2.Insert Nama"<<endl;
        cout<<"3.Delete First Index"<<endl;
        cout<<"4.Delete First Nama"<<endl;
        cout<<"5.Update Phone Book"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Masukan pilihan :"; cin>>pilih;
        switch(pilih){
        case 1 :
            cout<<"Masukan banyak Index : ";
            cin>>nd;
            for(int i=0;i<nd;i++){
                createElmtIndex(pd);
                insertFirstIndex(q,pd);
            }
        break;
        case 2 :cout<<"Masukan banyak Nama :";
            cin>>nk;
            traversalIndex(q);
            for(int i=0;i<nk;i++){
                createElmtContact(pk);
                insertFirstContact(q,key,pk);
            }
        break;
        case 3 :
            deleteFirstIndex(q,phd);
            traversalIndex(q);
        break;
        case 4:
            deleteFirstContact(q,key,phk);
            traversalIndContact(q);
        break;
        case 5 :
            traversalIndContact(q);
        break;
        default :
            exit(0);
        }
        system("pause");
    }while(pilih!=6);

}

