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

Program ini saya namai BST Visualizer, seperti namanya
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

## Dibuat Dengan

* [Sublime Text](https://www.sublimetext.com/) - Pembuatan .exe
* [DEV C++](https://sourceforge.net/projects/orwelldevcpp/) - IDE Utama


## Authors
* **Gelar Asto Bawono - (1910512034)** 

## Lisensi
Projek ini bersifat open source

## Terima Kasih Kepada
* Inspiration (pak DR. Achmad Solichin)
