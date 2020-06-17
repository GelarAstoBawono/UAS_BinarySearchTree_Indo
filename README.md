# UAS_BinarySearchTree_Indo
Dibuat dalam Bahasa Indonesia untuk Memudahkan dalam membaca sebuah fungsi

## Hayuuuk Lihat lebih dekat!

### Apa yang dibutuhkan?
Untuk Menjalankan File ini, anda hanya perlu mengunduh file "UAS_BST.exe" nya saja.
Jika Ingin Mengedit code yang ada, bisa kalian buka lewat aplikasi dibawah ini
```
- DEV C++
- Sublime Text 3
- Notepad Plus-Plus
```

## Menjalankan tests

Untuk Menjalankannya, anda hanya perlu mengunduh UAS_BST.exe yang ada
```
Disclaimer, karena extensionnya adalah .exe maka hanya pengguna Windows yang dapat membukanya,
dengan membukanya lewat IDE yang dipunya, dan dijalankan secara manual terlebih dahulu
```

### Hasil Test dan fitur dari program ini

Program ini saya beri nama BST Visualizer, seperti namanya
program ini akan membantu anda dalam:

```
- Memvisualisasikan BST yang ada
- Mengurutkan BST secara in, pre dan postOrder
- Menunjukkan value terkecil dan terbesar dalam program
```

Berikut beberapa code dan fitur yang ada

- *Fungsi Insert*
```
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
```

- *Fungsi In Order*
```
void BST :: Inorder(BST *root) {
    if(!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data <<"->" ;
    Inorder(root->right);
}
```

- *Fungsi Pre Order*
```
void BST :: preorderTraversal(BST *root) {
    if(!root) {
        return;
    }
    cout << root->data << "->";
  	preorderTraversal(root->left);
  	preorderTraversal(root->right);
}

```

- *Fungsi Post Order*
```
void BST :: postorderTraversal(BST *root) {
    if(!root) {
        return;
    }
  	postorderTraversal(root->left);
  	postorderTraversal(root->right);
  	cout << root->data << "->";
}
```
- *Menentukan Value Paling besar*
```
// Scanning value paling besar
int BST::maxValue(BST* node){
    BST* current = node;

	// dengan mencari lewat node paling kanan
    while (current && current->right != NULL)
        current = current->right;

    return current->data;
}
```

- *Menentukan Value Paling kecil*
```
// Scanning value paling kecil
int BST::minValue(BST* node){
    BST* current = node;

	// dengan mencari lewat node paling kiri
    while (current && current->left != NULL)
        current = current->left;

    return current->data;
}
```

*Disclaimer
```
Expect akan ada error jika dibuka di IDE yang berbeda
```
## Cara menggunakan program
```
- Buka program UAS_BST.exe
- Ketik angka "1" untuk memasukkan angka (memasukan angka secara satu per satu)
- Ketik angka "2" untuk mencari angka yang telah anda masukan ke dalam BST
- Ketik angka "3" untuk menghapus angka yang telah anda masukan ke dalam BST
- Ketik angka "4" untuk menampilkan urutan angka secara Inorder
- Ketik angka "5" untuk menampilkan urutan angka secara Preorder
- Ketik angka "6" untuk menampilkan urutan angka secara Postorder
- Ketik angka "7" untuk menghapus seluruh angka yang telah anda masukan ke dalam BST
- Ketik angka "8" untuk menampilkan angka terkecil dari angka yang telah anda masukan
- Ketik angka "9" untuk menampilkan angka terbesar dari angka yang telah anda masukan
- Ketik angka "0" untuk keluar/close program UAS_BST.exe
```
## Tampilan Program

Berikut adalah tampilan dari program UAS_BST.exe

![Screenshot (267)](https://user-images.githubusercontent.com/66856091/84842519-91ab4300-b06f-11ea-98a7-2a143d7fccb4.png)

## Dibuat Dengan

* [Sublime Text](https://www.sublimetext.com/) - Pembuatan .exe
* [DEV C++](https://sourceforge.net/projects/orwelldevcpp/) - IDE Utama


## Authors
* **Gelar Asto Bawono - (1910512034) - asto.bawono@gmail.com** 

## Lisensi
Projek ini bersifat open source

## Terima Kasih Kepada
* Inspiration (Dr. Achmad Solichin, S.Kom., M.T.I)
