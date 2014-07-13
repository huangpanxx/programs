#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class node {
    public:
	node() {
	    memset(childrens,0,sizeof(node*)*26);
	    n = 0;
	}
	node* childrens[26];
	int n;
};

int main() {
    int m,n;
    cin>>m;
    node root;
    while(m--){
	string s;
	cin>>s;
	node* p = &root;
	p->n += 1;
	for(int i=0;i<s.size();++i){
	    int k = s[i] - 'a';
	    if(p->childrens[k] == 0) {
		p->childrens[k] = new node;
	    }
	    p = p->childrens[k];
	    p->n += 1;
	}
    }

    cin>>n;
    while(n--) {
	string s;
	cin>>s;
	node*p = &root;
	for(int i=0;i<s.size();++i){
	    int k = s[i] - 'a';
	    p = p->childrens[k];
	    if(p == 0) {
		break;
	    }
	}
	if(p == 0)
	    cout << 0 << endl;
	else
	    cout << p->n << endl;
    }
    return 0;
}
