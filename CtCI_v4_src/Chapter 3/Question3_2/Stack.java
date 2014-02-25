package Question3_2;
class Stack {
	Node top;
	int pop() {
		if (top != null) {
			int item = top.data;
			top = top.next;
			return item;
		}
		return 0;
	}

	void push(int item) {
		Node t = new Node(item);
		t.next = top;
		top = t;
	}
}

class Node {
    public int data;
    public Node next;
    public Node(int v){
        data = v;
    }
}