#include <iostream>
using namespace std;

/*DECLARENYA Classnya terlebih dahulu*/
class BST {
    int data;
    BST *left, *right;
    public:
    // Default constructor.
    BST();
    BST(int);
    // Insert function.
    BST* Insert(BST *, int);
    // clearTree
	BST* delete_tree(BST *);
	// find node
	BST* find_node(BST *, int);
	// remove node
	BST* deleteNode(BST *, int);
	// Bagian Dari Delete
	BST* minValueNode(BST*);
	// Angka Terkecil
	int minValue(BST*);
	// Angka Terbesar
	int maxValue(BST*);
    // Inorder traversal.
    void Inorder(BST *);
    // preorderTraversal traversal.
	void preorderTraversal(BST *);
	// postorderTraversal traversal.
	void postorderTraversal(BST *);
};

// Posisi Default 
BST :: BST() : data(0), left(NULL), right(NULL){}

//delete biasa, tinggal delete kiri, kanan, ama dia sendiri
//gua tambahin return typenya dari void buat ngereplace tree yang ada di driver function
BST* BST::delete_tree(BST *root){
    if(root!=NULL){
        delete_tree(root->left);
        delete_tree(root->right);
        root=NULL;
    }
    return root;
}

// cari value yang sama saat insert, termasuk cek dia(Node) itu sendiri 
// searching akan berlanjut ke kiri jika nilainya lebih kecil dari yang dimasukkan 
// searching akan berlanjut ke kanan jika nilainya lebih besar dari yang dimasukkan
BST* BST::find_node(BST *root, int value){
    if(!root)
        return NULL;
    if(root->data == value)
        return root;
    if(root->data > value)
        return find_node(root->left, value);
    return find_node(root->right, value);
}

// Lanjutan fungsi Delete
BST*BST::minValueNode(BST* node){
    BST* current = node;

	// dengan mencari lewat node paling kiri
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Scanning value paling kecil
int BST::minValue(BST* node){
    BST* current = node;

	// dengan mencari lewat node paling kiri
    while (current && current->left != NULL)
        current = current->left;

    return current->data;
}

// Scanning value paling besar
int BST::maxValue(BST* node){
    BST* current = node;

	// dengan mencari lewat node paling kanan
    while (current && current->right != NULL)
        current = current->right;

    return current->data;
}

BST :: BST(int value) {
    data = value;
    left = right = NULL;
}

//Mencari dan Men-"Delete" node yang dicari
BST* BST::deleteNode(BST* root, int key){
    if (root == NULL) return root;

    // kalau datanya lebih kecil cek ke kiri
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // kalau besar ke kanan
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // kalo pas akan langsung di delete
    else{
        // kalo anaknya ga 2 yang dibawahnya akan langsung naik
        if (root->left == NULL){
            BST *temp = root->right;
            //free(root);
            return temp;
        }
        else if (root->right == NULL){
            BST *temp = root->left;
            //free(root);
            return temp;
        }

        // kalo 2 tukar sama Node paling kecil dikanan (MinValue)
        BST *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Fungsi Insert
BST* BST :: Insert(BST *root, int value) {
    if(!root) {
        // Memasukkan data pertama, jika rootnya kosong
        return new BST(value);
    }

    // Insert data.
    // Memasukkan data dengan mengecek nilai dari node yang akan dimasukkan
    if(value > root->data) {
		//Jika lebih besar dari node sebelumnya 
		//maka akan masuk ke node kanan
        root->right = Insert(root->right, value);
    }
    
    else{
		//Jika lebih kecil dari node sebelumnya 
		//maka akan masuk ke node kiri
        root->left = Insert(root->left, value);
    }
    
    // Setelah selesai, maka node yang dimasukkan akan menjadi root
    return root;
}

//Fungsi Inorder 
void BST :: Inorder(BST *root) {
    if(!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data <<"->" ;
    Inorder(root->right);
}

//Fungsi Pre Order
void BST :: preorderTraversal(BST *root) {
    if(!root) {
        return;
    }
    cout << root->data << "->";
  	preorderTraversal(root->left);
  	preorderTraversal(root->right);
}

//Fungsi Post Order
void BST :: postorderTraversal(BST *root) {
    if(!root) {
        return;
    }
  	postorderTraversal(root->left);
  	postorderTraversal(root->right);
  	cout << root->data << "->";
}

//Fungsi main
int main() {
    BST a, *root = NULL, *temp;
    bool condition_main;
    int x, menu_selection;
    condition_main = true;
	while (condition_main) {
    cout<<"============BST Visualizer===========\n";
    cout<<"\n";
	cout<<"1. Masukkan Angka ke BST          	\n";
    cout<<"2. Cari Angka dalam BST           	\n";
    cout<<"3. Delete Angka dalam BST         	\n";
    cout<<"4. Tampilkan BST dalam Inorder    	\n";
    cout<<"5. Tampilkan BST dalam PreOrder   	\n";
    cout<<"6. Tampilkan BST dalam PostOrder  	\n";
    cout<<"7. Clear BST                      	\n";
    cout<<"8. menampilkan Value terkecil di BST \n";
    cout<<"9. menampilkan Value terbesar di BST \n";
    cout<<"0. EXIT PROGRAM                   	\n";
    cout<<"\n";
    cout<<"Masukkan Pilihanmu= ";
    cin >> menu_selection;
    
    	switch (menu_selection) {
        	case 1: cout<<"Masukkan Angka= ";
					cin>> x;
    				root = a.Insert(root, x);
    				cout<<"Data Sudah Dimasukkan\n";
            		break ;

        	case 2: cout<<"Masukkan Angka= ";
					cin>> x;
    				if(a.find_node(root, x))
                        cout<<"Data ditemukan\n";
                    else
                        cout<<"Data tidak ditemukan\n";
            		break ;

            case 3: cout<<"Masukkan Angka= ";
					cin>> x;
					temp = a.deleteNode(root, x);
    				if(temp){
                        root = temp;
                        cout<<"Node berhasil dihapus\n";
    				}
                    else
                        cout<<"Data tidak ditemukan\n";
            		break ;

        	case 4: cout<<"Urutan dalam Inorder Traversal= \n";
					a.Inorder(root);
					cout<<"\n";
            		break ;

        	case 5: cout<<"Urutan dalam Pre Order Traversal= \n";
					a.preorderTraversal(root);
					cout<<"\n";
            		break ;

			case 6: cout<<"Urutan dalam Post Order Traversal= \n";
					a.postorderTraversal(root);
					cout<<"\n";
            		break ;

            case 7: root = a.delete_tree(root);
                    cout<<"Tree dikosongkan\n";
                    break;

			case 8: cout<<"Angka Terkecil\n"; 
					cout<< a.minValue(root);
					cout<<"\n";
                    break;

			case 9: cout<<"Angka Terbesar\n"; 
					cout<< a.maxValue(root);
					cout<<"\n";
                    break;

        	case 0: condition_main = false;
        			return 0;
					break;
        	default: cout<< "Pilihan menu salah, silahkan coba lagi.\n\n";
					break;
			}
		}
	}
