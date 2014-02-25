package OtherBasics;
class Node {
	Node next = null;
	int data;
	
	// Constructor
	public Node(int d) { data = d; }
	
	void appendToTail (int d) {
		Node end = new Node(d);
		Node n = this;
		while (n.next != null) { n = n.next; }
		n.next = end;
	}
	
	// Deleting a Node from a Singly Linked List
	Node deleteNode(Node head, int d) {
		Node n = head;
		if (n.data == d)      // THis case must be seperate from while-loop.
			return n.next;  // moved head !!!!!!!!!!!!!!!!!!
		while (n.next != null) {
			if (n.data == d) {
				n.next = n.next.next;    // skip the deleted node in the list
				return n;        //head didn't change.
			}
			n = n.next;
		}
		return null; // meaning d is absent in the LinkedList.
	}
}