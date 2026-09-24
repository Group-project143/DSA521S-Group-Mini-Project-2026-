public class QueueTaskA1 {

    // Student class
    static class Student {
        int studentNumber;
        String name;
        String serviceType;
        int serviceTime;

        // Constructor
        Student(int studentNumber, String name, String serviceType, int serviceTime) {
            this.studentNumber = studentNumber;
            this.name = name;
            this.serviceType = serviceType;
            this.serviceTime = serviceTime;
        }

        // Display student information
        void display() {
            System.out.println(
                    studentNumber + " | " +
                    name + " | " +
                    serviceType + " | " +
                    serviceTime + " min"
            );
        }
    }

    // Queue class
    static class StudentQueue {

        private Student[] queue;
        private int front;
        private int rear;
        private int size;

        // Constructor
        StudentQueue(int capacity) {
            queue = new Student[capacity];
            front = 0;
            rear = -1;
            size = 0;
        }

        // ENQUEUE
        public void enqueue(Student student) {

            if (size == queue.length) {
                System.out.println("Queue is full.");
                return;
            }

            rear = (rear + 1) % queue.length;
            queue[rear] = student;
            size++;

            System.out.println(student.name + " has joined the queue.");
        }

        // DEQUEUE
        public Student dequeue() {

            if (isEmpty()) {
                System.out.println("Queue is empty.");
                return null;
            }

            Student student = queue[front];

            queue[front] = null;
            front = (front + 1) % queue.length;
            size--;

            return student;
        }

        // PEEK
        public Student peek() {

            if (isEmpty()) {
                System.out.println("Queue is empty.");
                return null;
            }

            return queue[front];
        }

        // ISEMPTY
        public boolean isEmpty() {
            return size == 0;
        }

        // DISPLAY QUEUE
        public void displayQueue() {

            if (isEmpty()) {
                System.out.println("Queue is empty.");
                return;
            }

            System.out.println("\n===== WAITING QUEUE =====");

            int index = front;

            for (int i = 0; i < size; i++) {

                System.out.print((i + 1) + ". ");
                queue[index].display();

                index = (index + 1) % queue.length;
            }

            System.out.println("=========================");
        }
    }

    // MAIN METHOD
    public static void main(String[] args) {

        // Create queue
        StudentQueue queue = new StudentQueue(10);

        // Create six students
        Student student1 =
                new Student(221045678, "Maria", "Registration", 12);

        Student student2 =
                new Student(222034512, "Tomas", "Student Card", 5);

        Student student3 =
                new Student(223041876, "Ndapewa", "Fees", 8);

        Student student4 =
                new Student(221067341, "Simon", "Documents", 4);

        Student student5 =
                new Student(226019241, "David", "Academic Enquiry", 10);

        Student student6 =
                new Student(226075508, "Lambo", "Registration", 7);

        // Six students arrive
        System.out.println("===== STUDENT ARRIVALS =====");

        queue.enqueue(student1);
        queue.enqueue(student2);
        queue.enqueue(student3);
        queue.enqueue(student4);
        queue.enqueue(student5);
        queue.enqueue(student6);

        // Display queue
        queue.displayQueue();

        // Peek at first student
        System.out.println("\n===== PEEK =====");

        Student nextStudent = queue.peek();

        if (nextStudent != null) {
            System.out.println("Next student to be served:");
            nextStudent.display();
        }

        // Serve three students
        System.out.println("\n===== SERVING STUDENTS =====");

        Student served1 = queue.dequeue();

        if (served1 != null) {
            System.out.println("Served: " + served1.name);
        }

        Student served2 = queue.dequeue();

        if (served2 != null) {
            System.out.println("Served: " + served2.name);
        }

        Student served3 = queue.dequeue();

        if (served3 != null) {
            System.out.println("Served: " + served3.name);
        }

        // Display remaining students
        queue.displayQueue();

        // Check whether queue is empty
        System.out.println("\nIs queue empty? " + queue.isEmpty());
    }
}