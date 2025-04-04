#ifndef AVLTREE_H
#define AVLTREE_H

#include <cmath>
#include <iostream>

#define TREE_SIZE 1+2+4+8+16+32+64+128+256

// Todo: T instead of unsigned everywhere
class AVLTree {

    struct Node{
        unsigned key;
        bool initialized;

        unsigned depth;
        unsigned width;

        Node* left;
        Node* right;

        Node(): key(0), initialized(false), depth(0), width(0), left(nullptr), right(nullptr) {}
        Node(unsigned _key, unsigned _depth, unsigned _width): key(_key), initialized(true), depth(_depth), width(_width), left(nullptr), right(nullptr) {}
    };

    // Todo: allocate size_of(Node) * (2^0, 2^1, 2^2, 2^3, ..., 2^depth
    Node root[TREE_SIZE];

    public:
        AVLTree(): root{}{}
        ~AVLTree(){}

        void Insert(unsigned key) {
            if(!root[0].initialized){
                root[0] = Node(key, 0, 0);
                return;
            }

            Node* node = root;

            while(true){
                if(key == node->key){
                    return;
                }

                if(key < node->key){
                    if (node->left){
                        node = node->left;
                    } else {
                        unsigned minIndex = 0;
                        for(unsigned d = 0; d <= node->depth; d++){
                            minIndex += pow(2, d);
                        }
                        unsigned width = 2*node->width;
                        unsigned index = minIndex + width;
                        root[index] = Node(key, node->depth+1, width);
                        node->left = root + index;
                        return;
                    }
                } else {
                    if (node->right){
                        node = node->right;
                    } else {
                        unsigned minIndex = 0;
                        for(unsigned d = 0; d <= node->depth; d++){
                            minIndex += pow(2, d);
                        }
                        unsigned width = 2*node->width + 1;
                        unsigned index = minIndex + width;
                        root[index] = Node(key, node->depth+1, width);
                        node->right = root + index;
                        return;
                    }
                }
            }
        }

        void Print(){
            unsigned depth = 8; // currently 8
            for(unsigned d = 0; d < depth; d++){
                unsigned width = pow(2, d);
                for(unsigned w = 0; w < width; w++){
                    unsigned index = width-1 + w;
                    if(root[index].initialized){
                        std::cout << root[index].key << " ";
                    } else {
                        std::cout << "_ ";
                    }
                }

                std::cout << "\n";
            }
        }
};

#endif // AVLTREE_H
