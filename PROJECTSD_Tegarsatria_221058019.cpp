#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

typedef struct myLinkedList{
	string nama, namabuku;
	int no_anggota;
	myLinkedList *next;

}mylist;

mylist *head; mylist *tail;
int i;

void add_front(mylist *&H, mylist *&T){
	mylist *baru;
	baru=new mylist;
	cout<<"Mengisi data pada perpustakaan peminjaman akprind\n";
	cout<<"Nama              : ";cin>>baru->nama;
	cout<<"Buku yang dipinjam: ";cin>>baru->namabuku;
	cout<<"No Anggota        : ";cin>>baru->no_anggota;
	baru->next=NULL;
	if (H==NULL){
		H=baru;
		T=baru;}
	else{
		baru->next=H;
		H=baru;
	}
	cout<<" data anggota sudah berhasil ditambahkan\n";
}

void add_tail(mylist *&H, mylist *&T){
	mylist *baru;
	baru=new mylist;
	cout<<"Mengisi data pada perpustakaan peminjaman akprind pada posisi akhir \n";
	cout<<"Nama              : ";cin>>baru->nama;
	cout<<"Buku yang dipinjam: ";cin>>baru->namabuku;
	cout<<"No Anggota        : ";cin>>baru->no_anggota;
	baru->next=NULL;
	if (H==NULL){
		H=baru;
		T=baru;}
	else{
		T->next=baru;
		T=baru;
	}
	cout<<" data anggota sudah berhasil ditambahkan\n";
}

void print_linkedlist(mylist *H, mylist *T){
	mylist *dummy;
	dummy=new mylist;
	dummy=H;
	cout<<"Data yang ada di Perpustakaan Alprind saat ini:\n";
	cout<<"--------------------------------------\n";
	cout<<"No  Nama       NamaBuku          NoAng\n";
	cout<<"--------------------------------------\n";
	i=0;
	while (dummy!=NULL){
	   cout<<setw(2)<<++i<<setw(6)<<dummy->nama<<setw(15)<<
	   dummy->namabuku<<setw(15)<<dummy->no_anggota<<endl;
	   dummy=dummy->next;
	}	
	cout<<"--------------------------------------\n";
	cout<<"Jumlah data anggota yang meminjam buku : "<<i<<" Orang\n";
	delete dummy;
}

void add_position_byname(mylist *&H, mylist *&T){
	mylist *baru;
	baru=new mylist;
	cout<<"Mengisi data pada perpustakaan peminjaman akprind\n";
	cout<<"Nama              : ";cin>>baru->nama;
	cout<<"Buku yang dipinjam: ";cin>>baru->namabuku;
	cout<<"No Anggota        : ";cin>>baru->no_anggota;
	baru->next=NULL;
	mylist *dummy;
	dummy = new mylist;
	bool ada = false;
	string name;
	print_linkedlist(H,T);
	cout<<"Data akan diletakkan sesudah Data siapa? ";cin>>name;
	//cari si name didalam linked list
	dummy=H; //letakkan dummy diposisi head
	//cari kemungkinan name ada di posisi terakhir
	if(T->nama==name){
	  T->next=baru;
	  T=baru;
	  ada=true;
    }
	else{//name bukan posisi terakhir
	   while(dummy!=NULL){
		   if(dummy->nama==name){
			   baru->next=dummy->next;
			   dummy->next=baru;
			   ada=true;}
			  dummy=dummy->next;		   
	          }//end while
		}//end else
    if(ada) cout<<"data sudah berhasil disisipkan\n";
    else cout<<"Nama "<<name<<" Tidak ditemukkan \n";
}

void add_position_bynumber(mylist *&H, mylist *&T) {
	mylist *baru;
	baru=new mylist;
	cout<<"Mengisi data pada perpustakaan peminjaman akprind\n";
	cout<<"Nama              : ";cin>>baru->nama;
	cout<<"Buku yang dipinjam: ";cin>>baru->namabuku;
	cout<<"No Anggota        : ";cin>>baru->no_anggota;
	baru->next=NULL;
	int pos=0;
	print_linkedlist(H,T);
	ulang:
	cout<<" node baru ingin diletakkan diposisi berapa? ";cin>>pos;
	//valiadsikan
	if((pos<1) || (pos>i+1)){
	   cout<<"Nomor tidak valid, ulangi!";
	   goto ulang;
    }
    if(pos==1){
	baru->next=H;
	H=baru;
	}	
	else if (pos==(i+1)){
	T->next=baru;
	T=baru;	
	}
	else{
	mylist *dummy;
	dummy = new mylist;	
	dummy = H;
    int ii=0;
    while(dummy->next!=NULL){
		ii++;
		if(ii==(pos-1)){
			baru->next=dummy->next;
			dummy->next=baru;
			}
			dummy=dummy->next;
		}
    }
    cout<<"Data sudah diletakkan di posisi "<<pos<<endl;
}

void search_node_by_number(mylist *H, int no_anggota) {
    mylist *dummy = H;
    bool found = false;
    
    while (dummy != NULL) {
        if (dummy->no_anggota == no_anggota) {
            found = true;
            cout << "Data ditemukan:\n";
            cout << "Nama              : " << dummy->nama << endl;
            cout << "Buku yang dipinjam: " << dummy->namabuku << endl;
            cout << "No Anggota        : " << dummy->no_anggota << endl;
            break;
        }
        dummy = dummy->next;
    }
    
    if (!found) {
        cout << "Data tidak ditemukan.\n";
    }
}

void update_node_by_number(mylist *H, int no_anggota) {
    mylist *dummy = H;
    bool found = false;
    
    while (dummy != NULL) {
        if (dummy->no_anggota == no_anggota) {
            found = true;
            cout << "Data ditemukan.\n";
            cout << "Masukkan data baru:\n";
            cout << "Nama              : ";
            cin >> dummy->nama;
            cout << "Buku yang dipinjam: ";
            cin >> dummy->namabuku;
            break;
        }
        dummy = dummy->next;
    }
    
    if (!found) {
        cout << "Data tidak ditemukan.\n";
    }
}


void delete_node_atFirst(mylist *&H, mylist *&T){
	mylist *remove;
	remove = new mylist;
	remove = H;
	 cout<<"anda akan menghapus node terakhir dengan data sbb:\n";
	 cout<<"Nama        		: "<<remove->nama<<endl;
	 cout<<"Nama Buku        	: "<<remove->namabuku<<endl;
	 cout<<"No Anggota       	: "<<remove->no_anggota<<endl;
	char ya;
	cout<<"Yakin akan dihapus <y/t> ?";cin>>ya;
	if ((ya=='Y') || (ya=='y')){
			cout<<"Node sudah dihapus\n";
			H=remove->next;
			delete remove;
	}
	else cout<<"Node tidak jadi dihapus\n";
}

void delete_node_atLast(mylist *&H, mylist *&T){
   mylist *remove;
   remove = new mylist;
   if (H==T) delete_node_atFirst(H,T);
   else{
	  mylist *dummy; dummy=new mylist; dummy=H;
	  while(((dummy->next)->next)!=NULL) dummy=dummy->next;
	  remove=T;
	  cout<<"anda akan menghapus node terakhir dengan data sbb:\n";
	 cout<<"Nama        		: "<<remove->nama<<endl;
	 cout<<"Nama Buku        	: "<<remove->namabuku<<endl;
	 cout<<"No Anggota       	: "<<remove->no_anggota<<endl;
	  char ya;
	  cout<<"Yakin akan dihapus <y/t> ?";cin>>ya;
	  if ((ya=='Y') || (ya=='y')){
			cout<<"Node sudah dihapus\n";
			T=dummy;
			T->next=NULL;
			delete remove;}
	  else cout<<"Node tidak jadi dihapus\n";
    }
}

void delete_node_by_number(mylist *H,mylist *T, int no_anggota) {
    mylist *current = H;
    mylist *previous = NULL;
    bool found = false;
    
    while (current != NULL) {
        if (current->no_anggota == no_anggota) {
            found = true;
            cout << "Data ditemukan:\n";
            cout << "Nama              : " << current->nama << endl;
            cout << "Buku yang dipinjam: " << current->namabuku << endl;
            cout << "No Anggota        : " << current->no_anggota << endl;
            char ya;
            cout << "Yakin akan dihapus <y/t> ? ";
            cin >> ya;
            if (ya == 'Y' || ya == 'y') {
                cout << "Node berhasil dihapus.\n";
                if (previous != NULL) {
                    previous->next = current->next;
                } else {
                    H = current->next;
                }
                if (current == T) {
                    T = previous;
                }
                delete current;
            } else {
                cout << "Node tidak jadi dihapus.\n";
            }
            break;
        }
        previous = current;
        current = current->next;
    }
    
    if (!found) {
        cout << "Data tidak ditemukan.\n";
    }
}

void filtering(mylist *H, mylist *T) {
    mylist *dummy = H;
    int count = 0;
    
    while (dummy != NULL) {
        if (dummy->no_anggota > 9999) {
            cout<<"Data yang ada di Perpustakaan Alprind saat ini:\n";
			cout<<"--------------------------------------\n";
			cout<<"No  Nama       NamaBuku          NoAng\n";
			cout<<"--------------------------------------\n";
              cout<<setw(2)<<++count<<setw(6)<<dummy->nama<<setw(15)<<
			  dummy->namabuku<<setw(15)<<dummy->no_anggota<<endl;
        }
        dummy = dummy->next;
    }
    cout<<"--------------------------------------\n";
    cout << "Jumlah data anggota dengan nomor anggota lebih dari 4 digit: " << count << endl;
}

void manual_swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void manual_swap2(string &a, string &b){
	string temp = a;
	a = b;
	b = temp;
}

void sorting_descending(mylist *&H, mylist *&T) {
    mylist *current = H;
    int count = 0;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    int *no_anggota_array = new int[count];
    string *nama_array = new string[count];
    string *namabuku_array = new string[count];
    
    current = H;
    int i = 0;
    
    while (current != NULL) {
        no_anggota_array[i] = current->no_anggota;
        nama_array[i] = current->nama;
        namabuku_array[i] = current->namabuku;
        i++;
        current = current->next;
    }
    
    // Sorting array berdasarkan nomor anggota
    for (int j = 0; j < count - 1; j++) {
        for (int k = j + 1; k < count; k++) {
            if (no_anggota_array[j] < no_anggota_array[k]) {
            manual_swap(no_anggota_array[j], no_anggota_array[k]);
            manual_swap2(nama_array[j], nama_array[k]);
            manual_swap2(namabuku_array[j], namabuku_array[k]);
            }
        }
    }
    
    // Menampilkan data yang sudah diurutkan
    cout << "Data anggota setelah diurutkan secara naik (descending) berdasarkan nomor anggota:\n";
    cout << "------------------------------------------------------------------------\n";
    cout << "No  Nama       NamaBuku          NoAng\n";
    cout << "------------------------------------------------------------------------\n";
    
    for (int j = 0; j < count; j++) {
        cout << setw(2) << j + 1 << setw(6) << nama_array[j] << setw(15) << namabuku_array[j] << setw(15) << no_anggota_array[j] << endl;
    }
    
    cout << "------------------------------------------------------------------------\n";
    
     delete[] no_anggota_array ;
     delete[] nama_array ;
     delete[] namabuku_array ;
     
}

// Fungsi untuk melakukan sorting secara naik (ascending) berdasarkan nomor anggota
void sorting_ascending(mylist *&H, mylist *&T) {
    mylist *current = H;
    int count = 0;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    int *no_anggota_array = new int[count];
    string *nama_array = new string[count];
    string *namabuku_array = new string[count];
    
    current = H;
    int i = 0;
    
    while (current != NULL) {
        no_anggota_array[i] = current->no_anggota;
        nama_array[i] = current->nama;
        namabuku_array[i] = current->namabuku;
        i++;
        current = current->next;
    }
    
    // Sorting array berdasarkan nomor anggota
    for (int j = 0; j < count - 1; j++) {
        for (int k = j + 1; k < count; k++) {
            if (no_anggota_array[j] > no_anggota_array[k]) {
            manual_swap(no_anggota_array[j], no_anggota_array[k]);
            manual_swap2(nama_array[j], nama_array[k]);
            manual_swap2(namabuku_array[j], namabuku_array[k]);
            }
        }
    }
    
    // Menampilkan data yang sudah diurutkan
    cout << "Data anggota setelah diurutkan secara naik (ascending) berdasarkan nomor anggota:\n";
    cout << "------------------------------------------------------------------------\n";
    cout << "No  Nama       NamaBuku          NoAng\n";
    cout << "------------------------------------------------------------------------\n";
    
    for (int j = 0; j < count; j++) {
        cout << setw(2) << j + 1 << setw(6) << nama_array[j] << setw(15) << namabuku_array[j] << setw(15) << no_anggota_array[j] << endl;
    }
    
    cout << "------------------------------------------------------------------------\n";
    
     delete[] no_anggota_array ;
     delete[] nama_array ;
     delete[] namabuku_array ;
}

int main(){
    head=NULL;tail=NULL;
    int pilih=0;
    do{
    system("cls");
    cout<<" Menu Pengelolaan Data Perpustakaan Akprind "<<endl;
    cout<<"1. Tambah di awal node \n";
    cout<<"2. Tambah di akhir node \n";
    cout<<"3. Tambah di posisi tertentu \n";
    cout<<"4. Tambah node di nomor tertentu \n";
    cout<<"5. Cetak Data Linked List\n";
    cout<<"6. Hapus node pertama\n";
    cout<<"7. Hapus node terakhir\n";
    cout<<"8. Cari Data Berdasarkan No Anggota\n";
    cout<<"9. Update Data Berdasarkan No Anggota\n";
    cout<<"10. Hapus Data Berdasarkan No Anggota\n";
    cout<<"11. Filtering no anggota lebih dari 4 digit angka\n";
    cout<<"12. Sorting Descending Dari No Anggota Terbesar hingga terkecil\n";
    cout<<"13. Sorting Ascending Dari No Anggota Terkecil hingga terbesar\n";
    cout<<"0. Selesai\n";
    cout<<"Pilih menu : ";cin>>pilih;
    switch(pilih){
        case 1: add_front(head,tail);break;
        case 2: add_tail(head,tail);break;
        case 3: if (head==NULL) cout<<"Data Kosong \n"; else {add_position_byname(head,tail);break;}
        case 4: if (head==NULL) cout<<"Data Kosong \n"; else {add_position_bynumber(head,tail);break;}
        case 5: if (head==NULL) cout<<"Data Kosong \n"; else {print_linkedlist(head,tail);break;}
        case 6: if (head==NULL) cout<<"Data Kosong \n"; else {delete_node_atFirst(head,tail);break;}
        case 7: if (head==NULL) cout<<"Data Kosong \n"; else {delete_node_atLast(head,tail);break;}
        case 8: if (head==NULL) cout << "Data Kosong\n"; else { int no; cout << "Masukkan No Anggota yang ingin dicari  : "; cin >> no; search_node_by_number(head, no); break;}
        case 9: if (head==NULL) cout << "Data Kosong\n"; else { int no; cout << "Masukkan No Anggota yang ingin diupdate: "; cin >> no; update_node_by_number(head, no); break;}
        case 10: if (head==NULL) cout << "Data Kosong\n"; else { int no; cout << "Masukkan No Anggota yang ingin dihapus: "; cin >> no; delete_node_by_number(head,tail,no); break;}
        case 11: if (head==NULL) cout<<"Data Kosong \n"; else {filtering(head,tail);break;}
        case 12: if (head==NULL) cout<<"Data Kosong \n"; else {sorting_descending(head,tail);break;}
        case 13: if (head==NULL) cout<<"Data Kosong \n"; else {sorting_ascending(head,tail);break;}
        case 0: cout<<"Terima Kasih\n";break;
        default : cout<<"Salah Pilih Menu\n";break;
    }
    system("pause");
    }
    while(pilih!=0);
    delete head; delete tail;
}
