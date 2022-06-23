#include<iostream>
#include<vector>
#include<algorithm>

/*
 * tree  2->3->4 2->3->5->6
 [ 2 3 4  ]
 [ 3 2 5  ]
 [ 4 2  ]
 [ 5 3 6  ]
 [ 6 5  ]
 3 5 6 
 2  4 
 3  2 4 
 3 5 6 
 4 2 
 5 3 2 4 
 5 6 
 6 5
 root -> leaf path => [ 2 3 5 6  ]
 root -> leaf path => [ 2 4  ]
 */


using namespace std;

struct node {
	int v;
	struct node *l;
	struct node *r;
};

/*This compute edges and find all the possible paths*/
/*we store numbers ref node to whcih all nodes are connected as indexes and connected nodes as vectors to it
 * the compute find all edges. 
 * to find the largest path, simply compare the root and leaf to the computed path
 */

class Tree {
	public:
		struct node *node;
		vector<vector<int>> tmap{10, vector<int>()};
		vector<vector<int>> paths{10, vector<int>()};
		vector<int> leafs;


		void print_paths()
		{
			vector<vector<int>>::iterator t = paths.begin();
			vector<int> v;
			vector<int>::iterator _t;
			for(; t != paths.end(); ++t) {
				v = *t;
				if (v.size() == 0) continue;
				for(_t = v.begin(); _t != v.end(); _t++)
					cout <<*_t <<" ";
				cout << endl;
			}


		}

		void addnode(struct node **n, int l , int r)
		{
			struct node *p = *n;
			if ( l != -1) {
				p->l = new struct node;
				p->l->v = l;
				p->l->l = 0;
				p->l->r = 0;
			}
			if ( r == -1) return;
			p->r = new struct node;
			p->r->v = r;
			p->r->l = 0;
			p->r->r = 0;
		}

		void get_path_from_root_to_leaf()
		{
			//_f() computes all the path possible
			//we are not interested in that.
			//if leaf is the last node and first node is root, we have our paths

			vector<vector<int>>::iterator t = paths.begin();
			vector<int> v;
			vector<int>::iterator _t;
			for(; t != paths.end(); ++t) {
				v = *t;
				if (v[0] == node->v && (*(v.end()-1) ==leafs[0] ||  *(v.end()-1) ==leafs[1])){
					cout<<"root -> leaf path => ";
					cout<<"[ ";
					for ( _t = v.begin(); _t != v.end(); ++_t)
						cout <<*_t<<" ";
					cout<<" ]"<<endl;
				}
			}
		}

		void _f(int a, int b, vector<int> &v)
		{
			/*if the vector is of size 1, it is just one single edge*/
			if(tmap[a].size() == 1) {
				v.push_back(a);
				v.push_back(b);
				return;
			}
			v.push_back(a);
			/*last element */
			if (tmap[b][0] == a && tmap[b].size() == 1) {
				v.push_back(b);
				return;
			}
			/*this is a case when the vector[a] first element and b does not matches*/
			if (tmap[b][0] != a)
				_f(b, tmap[b][0], v);
			else
				_f(b, tmap[b][1], v);
		}

		/*
		 * algo: how to print path
		 * look at first and print the path
		 */
		void compute_path()
		{

			vector<vector<int>>::iterator t = tmap.begin();
			vector<int> v;
			vector<int>::iterator _t;

			int path = 0;

			for(int i = 0; t != tmap.end(); ++t, ++i) {
				v = *t;
				_t = v.begin();
				if (v.size() == 0) continue;

				for ( int j = 0; j < v.size(); ++j) {
					_f(i, v[j], paths[path]);
					++_t;
					path++;
				}
			}

			print_paths();



		}




		/*this wil print tree edge map*/
		void print()
		{
			vector<vector<int>>::iterator t = tmap.begin();
			vector<int> v;
			vector<int>::iterator _t;
			for(int i = 0; t != tmap.end(); ++t, ++i) {

				v = *t;
				if (v.size() == 0) continue;


				cout <<"[ "<<i<<" ";
				for (_t = v.begin(); _t != v.end(); ++_t)
					cout <<*_t <<" ";

				cout <<" ]"<<endl;

			}

		}
		void edges(struct node *n)
		{

			if (n == 0) return;

			/*aha! our leafs*/
			if(n->l == 0 && n->r == 0) 
				leafs.push_back(n->v);

			if(n->l != 0)
				tmap[n->v].push_back(n->l->v);
			if(n->l != 0)
				tmap[n->l->v].push_back(n->v);
			edges(n->l);
			if(n->r != 0)
				tmap[n->v].push_back(n->r->v);
			if(n->r != 0)
				tmap[n->r->v].push_back(n->v);
			edges(n->r);
			/* traverse node and add them in array*/
		}
};


int main()
{
	Tree t;
	t.node = new struct node;
	t.node->v = 2;
	t.addnode(&t.node, 3, 4);
	t.addnode(&t.node->l, 5, -1);
	t.addnode(&t.node->l->l, 6, -1);
	t.edges(t.node);
	t.print();
	t.compute_path();
	t.get_path_from_root_to_leaf();
	return 0;
}



