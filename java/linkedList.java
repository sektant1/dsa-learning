import java.util.*;

class ListTest {
	public static void main(String[] args) {
		LinkedList<Integer> intList = new LinkedList<Integer>();
		ChadList myList = new ChadList();

		myList.add(45);
		myList.add(8);
		myList.add(22);

		intList.add(45);
		intList.add(8);
		intList.add(22);

		System.out.println(intList);
		System.out.println(myList);
	}
}
