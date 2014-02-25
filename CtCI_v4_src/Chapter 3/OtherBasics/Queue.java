package OtherBasics;

class Queue{
	Node head,back;
	void enqueue(int item) {
		if (head != null) {
			Node t = new Node(item);
//			t.next = back; WRONG!!! 2012-2-13 22:02:57 by ziegfeld
			back.next = t;
			back = t;
		}
		else {
			back = new Node(item);
			head = back;
		}
	}
	int dequeue() {
		if (head != null) {
			int item = head.data;
			head = head.next;
			return item;
		}
		return 0;
	}
}