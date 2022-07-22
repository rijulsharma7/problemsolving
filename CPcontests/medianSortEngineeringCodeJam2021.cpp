#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class node {
public:
    ll data;
    node*left;
    node*right;
    node(ll d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};


// took reference from https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/



void storeBSTNodes(node* root, vector<node*> &nodes)
{
    if (root == NULL)
        return;

    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}

node* buildTreeUtil(vector<node*> &nodes, ll s,
                    ll e)
{

    if (s > e)
        return NULL;
    ll mid = (s + e) / 2;
    node *root = nodes[mid];
    root->left  = buildTreeUtil(nodes, s, mid - 1);
    root->right = buildTreeUtil(nodes, mid + 1, e);

    return root;
}

node* buildTree(node* root)
{
    vector<node *> nodes;
    storeBSTNodes(root, nodes);

    ll n = nodes.size();
    return buildTreeUtil(nodes, 0, n - 1);
}

void inorder(node*root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

ll insert(node* root, ll dir, ll d) {


    if (dir == 1) {
        if (root->left == NULL) {
            root->left = new node(d);
        }
        else {
            cout << root->data << " " << root->left->data << " " << d << '\n';
            cout << flush;
            ll med;
            cin >> med;
            if (med == -1) {
                return -1 ;
            }
            if (med == d) {
                insert(root->left, 2, d);
            }
            else if (med == root->data) {
                insert(root, 2, d);

            }
            else if (med == root->left->data) {
                insert(root->left, 1, d);

            }
        }

    }
    else {
        if (root->right == NULL) {
            root->right = new node(d);
        }
        else {
            cout << root->data << " " << root->right->data << " " << d << '\n';
            cout << flush;
            ll med;
            cin >> med;
            if (med == -1) {
                return -1 ;
            }
            if (med == d) {
                insert(root->right, 1, d);
            }
            else if (med == root->data) {
                insert(root, 1, d);

            }
            else if (med == root->right->data) {
                insert(root->right, 2, d);
            }
        }


    }

    return 1;
}





int main() {
    ll t, n, q;
    cin >> t >> n >> q;
    while (t--) {
        cout << 1 << " " << 2 << " " << 3 << '\n';
        ll med;
        cin >> med;
        node* root;
        if (med == 1) {
            root = new node(1);
            root->left = new node(2);
            root->right = new node(3);

        }
        else if (med == 2) {
            root = new node(2);
            root->left = new node(1);
            root->right = new node(3);
        }
        else {
            root = new node(3);
            root->left = new node(1);
            root->right = new node(2);

        }
        for (ll i = 4; i <= n; i++) {
            ll x = insert(root, 1, i);
            if (x == -1) {
                return 0;
            }
            root = buildTree(root);
        }

        inorder(root);
        cout << '\n';
        cout << flush;
        ll ans;
        cin >> ans;
        if (ans == 1) {
        }
        else {
            return 0;
        }

    }
    return 0;

}