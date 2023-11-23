#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol
struct TreeNode {
    int data;
    int nodeId;  // Identificador para cada nodo
    struct TreeNode *left;
    struct TreeNode *right;
};

// Variables globales para el identificador de nodo
int nodeIdCounter = 1; // Inicializar el contador de nodo

// Función para asignar un identificador único a cada nodo
void assignNodeIds(struct TreeNode *root) {
    if (root != NULL) {
        root->nodeId = nodeIdCounter++;
        assignNodeIds(root->left);
        assignNodeIds(root->right);
    }
}
// Función para crear un nuevo nodo del árbol
struct TreeNode *createNode(int value) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Función para insertar un nuevo nodo en el árbol
struct TreeNode *insert(struct TreeNode *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Función para mostrar el árbol de manera inorder (izquierda, raíz, derecha)
void display(struct TreeNode *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int comprobar(struct TreeNode *root) {
    if (root == NULL) {
        return 1; 
    }

    if ((root->left != NULL && root->data < root->left->data) ||
        (root->right != NULL && root->data > root->right->data)) {
        return 0; 
    }

    if (!comprobar(root->left) || !comprobar(root->right)) {
        return 0;
    }

    return 1;
}


// Función para buscar un valor en el árbol
struct TreeNode *findWithDetails(struct TreeNode *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return findWithDetails(root->left, value);
    } else {
        return findWithDetails(root->right, value);
    }
}

void addData(struct TreeNode **root) {
    int value;
    char choice;

    do {
        printf("Ingrese un valor: ");
        scanf("%d", &value);

        *root = insert(*root, value);

        printf("¿Agregar otro dato? (s/n): ");
        scanf(" %c", &choice);
    } while (choice == 's' || choice == 'S');
}

int main() {
    struct TreeNode *root = NULL;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    //Aqui se hace el cambio al arbol, si lo comentas el arbol seguira correcto
    root->left->left->data = 9; 

    if (comprobar(root)) {
        printf("El árbol es un árbol binario de búsqueda.\n");
    } else {
        printf("El árbol no es un árbol binario de búsqueda.\n");
    }

    // printf("Ingrese valores para agregar al árbol (Ingrese 'n' para terminar):\n");
    // addData(&root);

    // printf("Árbol de búsqueda binaria resultante: ");
    // display(root);
    // printf("\n");

    // assignNodeIds(root);

    // printf("Introduce el valor a buscar: ");
    // int searchValue;
    // scanf("%d", &searchValue);

    // struct TreeNode *resultNode = findWithDetails(root, searchValue);
    // if (resultNode != NULL) {
    //     printf("%d encontrado en el nodo %d.\n", searchValue, resultNode->nodeId);

    //     if (resultNode->left != NULL) {
    //         printf("Nodo izquierdo: %d\n", resultNode->left->nodeId);
    //     } else {
    //         printf("No hay nodo izquierdo.\n");
    //     }

    //     if (resultNode->right != NULL) {
    //         printf("Nodo derecho: %d\n", resultNode->right->nodeId);
    //     } else {
    //         printf("No hay nodo derecho.\n");
    //     }
    // } else {
    //     printf("%d no encontrado en el árbol.\n", searchValue);
    // }

    return 0;
}
