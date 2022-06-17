#include<iostream>
#include<vector>
#include<list>


using namespace std;

struct node{
	int v;
	struct node* l;
	struct node* r;
};

class Bin_tree {
	public:
		Bin_tree(){node = 0;}

		struct node* node;
		list <struct node*>q;

		void print()
		{

			cout<<"inorder ->  ";
			print_inorder(node);
			cout <<"\n" << "preorder ->";
			print_preorder(node);
			cout <<"\n" << "postorder ->";
			print_postorder(node);
			cout <<"\n" << "level order ->";
			print_levelorder(node);
		}

		void print_q(list<struct node*>& l)
		{

			list<struct node*>::iterator it = l.begin();

			cout<<"queue size " << l.size()<<endl;

			for (; it != l.end(); ++it)
				cout <<"Ptr -> "<<*it;
			cout<<"\n";

		}



		/*breadth first or level order
		 *
		 */

		void print_levelorder(struct node* n)
		{
			if (n == 0)return;
			cout <<n->v <<" ";
			if (n->l)q.push_back(n->l);
			if (n->r)q.push_back(n->r);

			while (q.size() != 0) {
				struct node*_n = q.front();
				q.pop_front();
				cout << _n->v <<" ";
				if (_n->l)q.push_back(_n->l);
				if (_n->r)q.push_back(_n->r);
			}

		}

		/*post order -> left, right, root
		 *
		 *
		 */
		void print_postorder(struct node *n)
		{
			if (n == 0)return;
			print_postorder(n->l);
			print_postorder(n->r);
			cout<<n->v<<" ";
		}

		/*
		 *100->20,200
		 *20->10,30
		 *200->150, 300
		 */

		/*pre order - root, left, right*/
		void print_preorder(struct node *n)
		{
			if (n == 0)return;
			cout << n->v << " ";
			print_preorder(n->l);
			print_preorder(n->r);

		}

		/*inorder -> left node, root, right node
		 *
		 *
		 */
		void print_inorder(struct node *n)
		{

			if (n == 0) { return;}
			print_inorder(n->l);
			cout <<n->v <<" ";
			print_inorder(n->r);
		}

		void print_tree(struct node *n)
		{
			if( n != 0) {
				cout << "root " << n << "value " << n->v << "\n";
				if(n->l != 0)
					cout << "left " << n->l << "value " << n->l->v << "\n";
				if(n->r != 0)
					cout << "right " << n->r << "value " << n->r->v <<"\n";
				print_tree(n->l);
				print_tree(n->r);
			}
		}

		void add(int v)
		{
			if (node == 0)
				add_node(&node, &node, v);
			else if (v > node->v) add_node(&node, &node->r, v);
			else if (v < node->v) add_node(&node, &node->l, v);

		}
		void add_node(struct node** p, struct node** node, int v)
		{
			struct node *_node;
			if (*node == 0){
				_node  = new struct node;
				_node->v = v;
				_node->l = 0;
				_node->r = 0;
				if(*p != 0) {
					if (v > (*p)->v )(*p)->r = _node;
					else (*p)->l = _node;
				}
				else *node = _node;
			}
			else if ( v > (*node)->v) {
				add_node(node, &((*node)->r), v);
			}
			else
				add_node(node, &((*node)->l), v);
		}
};

int main()
{
	Bin_tree t;

	/*
	 *				 100
	 *				/	\
	 *             20	200
	 *			  /  \	 /  \
	 *			 10	 30 150	 300
	 */
	list<int> l({100, 20, 200, 10, 30, 150, 300});
	list<int>::iterator i = l.begin();
#if 0
	t.add(10);
	cout << "node added  " <<t.node <<"  "<<t.node->l  <<"  "<< t.node->r <<"\n";
	t.add(11);
	cout << "node added  " <<t.node <<"  "<<t.node->l  <<"  "<< t.node->r <<"\n";
	t.add(9);
	cout << "node added  " <<t.node <<"  "<<t.node->l  <<"  "<< t.node->r <<"\n";
	t.add(8);
	cout << "node added  " <<t.node <<"  "<<t.node->l  <<"  "<< t.node->r <<"\n";
#endif
	for(; i != l.end(); i++)
		t.add(*i);	
	t.print();

	return 0;
}

