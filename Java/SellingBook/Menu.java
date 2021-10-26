package SellingBook;

import java.util.Scanner;

public class Menu {

    public static int k;
    public static String s;
    public static String exit = "khong";
    public static Cart GioHang = new Cart();
    public static Cart KeHang = new Cart();
    static Scanner cin = new Scanner(System.in);
    static Scanner gets = new Scanner(System.in);
    //thong tin ve sachBook
    public static Book a = new Book("Alchemist", 10, 10, new String[]{"Paulo Coelho"});
    public static Book b = new Book("Gris", 20, 1, new String[]{"Conrad Roset", " Nomada Studio"});
    public static Book c = new Book("Harry Potter", 100, 7, new String[]{"J. K. Rowling"});
    public static Book d = new Book("The Little Prince", 7.99, 3, new String[]{"Antoine De Saint-Exupery"});

    public static void Themkehang() {
        KeHang.addBookToCart(a);
        KeHang.addBookToCart(b);
        KeHang.addBookToCart(c);
        KeHang.addBookToCart(d);
    }

    public static void Kesach() {
        KeHang.displayCart();
    }

    public static void Process(int k) {
        switch (k) {
            case 1:
                //Hien thi danh sach ke hang
                Kesach();
                break;
            case 2:
                //Hien thi danh sach cac sach ban da chon
                GioHang.displayCart();
                break;
            case 3:
                //Lay 1 cuon sach ban muon
                System.out.printf("Write a book name u want: ");
                s = gets.nextLine();
                KeHang.addBookNameToCart(s, GioHang);
                break;
            case 4:
                //Lay them 1 cuon sach ban muon
                System.out.printf("Write a numerical order (Begin at 0): ");
                GioHang.displayCart();
                k = cin.nextInt();
                GioHang.getBookfromList(k);
                break;
            case 5:
                //Xoa 1 cuon ban da chon
                System.out.printf("Write the book name: ");
                s = gets.nextLine();
                KeHang.deleteBookfromCart(s, GioHang);
                break;
            case 6:
                //Xoa tat ca sach ban da chon
                GioHang.deleteAll();
                break;
            case 7:
                //Tong so tien
                GioHang.calTotal();
                System.out.println(GioHang.total);
                break;
            case 8:
                //Tong so sach ban da chon
                System.out.println("Total books: " + GioHang.countBook());
                break;
            case 9:
                //Sap xep theo TEN SACH ma ban da chon
                System.out.println("0.Increase");
                System.out.println("1.Decrease");
                k = cin.nextInt();
                GioHang.sortbyName(k);
                break;
            case 10:
                //Sap xep theo GIA SACH ma ban da chon
                System.out.println("0.Increase");
                System.out.println("1.Decrease");
                k = cin.nextInt();
                GioHang.sortbyPrice(k);
                break;
            case 11:
                //sua thong tin 1 cuon sach
                System.out.printf("Write the book name: ");
                s = gets.nextLine();
                KeHang.setBookfromList(s);
                break;
            case 12:
                //thoat
                exit = "co";
                break;
        }
    }

    public static void Form() {
        System.out.println("Select the number:");
        System.out.println("1.Display Libary");
        System.out.println("2.Display your cart");
        System.out.println("3.Get a new book");
        System.out.println("4.Take more books");
        System.out.println("5.Delete the book you want");
        System.out.println("6.Delete all");
        System.out.println("7.Your bill");
        System.out.println("8.Total books");
        System.out.println("9.Sort book by Name");
        System.out.println("10.Sort book by Price");
        System.out.println("11.Set information for the book");
        System.out.println("12.EXIT");
    }

    public static void Menu() {
        Themkehang();

        do {
            System.out.printf("Display Menu:(yes or no): ");
            s = gets.nextLine();
            s = s.toLowerCase();
            if (s.equals("yes")) {
                Form();
            }
            k = cin.nextInt();
            Process(k);
        } while (exit.equals("khong"));
    }
}
