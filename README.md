# UAS_BinarySearchTree_Indo
Dibuat dalam Bahasa Indonesia untuk Memudahkan dalam membaca sebuah fungsi/ Line

## Hayuuuk Lihat lebih dekat!

### Apa yang dibutuhkan?
Untuk Menjalankan File ini, anda hanya perlu mengunduh file "UAS_BST.exe" nya saja
Jika Ingin Mengedit code yang ada, bisa kalian buka lewat aplikasi dibawah ini
```
- DEV C++
- Sublime Text 3
- Notepad Plus-Plus
```

## Menjalankan tests

Untuk Menjalankannya, anda hanya perlu mengunduh UAS_BST.exe yang ada
```
Disclaimer, karena extensionnya adalah .exe maka pengguna IOS selain OS dapat membukanya
dengan membukanya lewat IDE yang dipunya, dan dijalankan secara manual terlebih dahulu
```

### Hasil Test dan fitur dari program ini

Program ini saya namai BST Visualizer, seperti namanya
program ini akan membantu anda dalam:

```
- Memvisualisasikan BST yang ada
- Mengurutkan BST secara in, pre dan postOrder
```

Berikut beberapa code dan fitur yang ada

- *Fungsi Insert*
```
BST* BST :: Insert(BST *root, int value) {
    if(!root) {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    // Insert data.
    if(value > root->data) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else{
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion.
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
