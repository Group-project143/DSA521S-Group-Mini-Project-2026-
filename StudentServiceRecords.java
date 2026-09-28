public class StudentServiceRecords {
    static class Node {
        String studentNo;
        String Name;
        String serviceType;
        int serviceTime;
        Node next;

        Node(String studentNo, String Name,
             String serviceType, int serviceTime) {

            this.studentNo = studentNo;
            this.Name = Name;
            this.serviceType = serviceType;
            this.serviceTime = serviceTime;
            this.next = null;
        }
    }

    Node head = null;

    public void insertStudent(String number, String name,
                               String service, int time) {

        Node newNode = new Node(number, name, service, time);

        newNode.next = head;
        head = newNode;
    }
    public void insertAtEnd(String number, String name,
                             String service, int time) {

        Node newNode = new Node(number, name, service, time);

        if (head == null) {
            head = newNode;
            return;
        }

        Node temp = head;

        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newNode;
    }
    public void insertAtPosition(String number, String name,
                                  String service, int time,
                                  int position) {

        Node newNode = new Node(number, name, service, time);

        if (position == 1) {
            newNode.next = head;
            head = newNode;
            return;
        }

        Node temp = head;

        for (int i = 1; i < position - 1 && temp != null; i++) {
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println("Invalid position.");
            return;
        }

        newNode.next = temp.next;
        temp.next = newNode;
    }
    public void deleteStudent(String number) {

        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        if (head.studentNo.equals(number)) {
            head = head.next;
            System.out.println("Student deleted.");
            return;
        }

        Node temp = head;

        while (temp.next != null &&
               !temp.next.studentNo.equals(number)) {

            temp = temp.next;
        }

        if (temp.next == null) {
            System.out.println("Student not found.");
        } else {
            temp.next = temp.next.next;
            System.out.println("Student deleted.");
        }
    }
    public void searchStudent(String number) {

        Node temp = head;

        while (temp != null) {

            if (temp.studentNo.equals(number)) {
                System.out.println("Student found:");
                System.out.println("Student Number: " + temp.studentNo);
                System.out.println("Name: " + temp.Name);
                System.out.println("Service: " + temp.serviceType);
                System.out.println("Service Time: " + temp.serviceTime + "minutes");
                return;
            }

            temp = temp.next;
        }

        System.out.println("Student not found.");
    }
    public void displayStudents() {

        Node temp = head;

        if (temp== null) {
            System.out.println("No student records.");
            return;
        }

        while (temp != null) {

            System.out.println(
            "[" + temp.studentNo + " ]" +
            "[" + temp.Name + " ]" +
            "[" + temp.serviceType + 
          " ][" +temp.serviceTime + " minutes" + "]");

            temp = temp.next;
        }
    }

    public static void main(String[] args) {

        StudentServiceRecords list = new StudentServiceRecords();

    
        list.insertStudent("221045678", "Maria", "Registration", 12);

        list.insertAtEnd( "222034512", "Tomas", "Student Card", 5 );

        
        list.insertAtEnd( "223041876", "Ndapewa", "fees", 8);
             
      
        list.insertAtPosition("221067341", "Simon", "Documents", 4, 3);

        System.out.println("STUDENT SERVICE RECORDS");
        list.displayStudents();

        
         System.out.println("\nSearch FOR Student");
         list.searchStudent("222034512");
       
        System.out.println("\nDelete Student:");
        list.deleteStudent("222034512");
        
        System.out.println("\nStudent sevice recodes after a student is deleted:");
        list.displayStudents();
        
    }
}
