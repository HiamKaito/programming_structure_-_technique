package SellingBook;

import java.util.Arrays;
import java.util.Scanner;

public class Book {

    private String name;            // ten sach
    private double price;           //gia
    private int amount;             //so luong
    private int count = 0;            //dem so luong sach lay ra
    private String[] id_Authors;    //tac gia

    Scanner cin = new Scanner(System.in);

    public Book() {
    }

    public Book(String name, double price, int amount, String[] id) {
        this.name = name;
        this.price = price;
        this.amount = amount;
        this.id_Authors = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public String[] getId_Authors() {
        return id_Authors;
    }

    public void setId_Authors(String[] id_Authors) {
        this.id_Authors = id_Authors;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    void addAuthor() {
        //nhap so luong tac gia
        int numOfAuthor;
        System.out.printf("\n\tNumber of author: ");
        numOfAuthor = Integer.parseInt(cin.nextLine());
        id_Authors = new String[numOfAuthor];
        for (int i = 0; i < numOfAuthor; i++) {
            id_Authors[i] = cin.nextLine();
        }
    }

    public void getInfo() {
        //nhap thong tin cho tung muc
        System.out.printf("Name of book: ");
        setName(cin.nextLine());
        System.out.printf("Price of book: ");
        setPrice(Double.parseDouble(cin.nextLine()));
        System.out.printf("Name author of book: ");
        addAuthor();
        System.out.printf("Amount of book: ");
        setAmount(Integer.parseInt(cin.nextLine()));
    }

    public void setInfo(Book a) {
        //sua thong tin cho tung muc
        this.name = a.name;
        this.price = a.price;
        this.amount = a.amount;
        this.id_Authors = a.id_Authors;
    }

    public void setInfo(String name, double price, int amount, String[] id) {
        //sua thong tin cho tung muc
        this.name = name;
        this.price = price;
        this.amount = amount;
        this.id_Authors = id;
    }

    public static int NameTangdan(Book a, Book b) {
        return a.name.compareTo(b.name);
    }

    public static int NameGiamdan(Book a, Book b) {
        return b.name.compareTo(a.name);
    }

    public static int PriceTangdan(Book a, Book b) {
        if (a.price < b.price) {
            return -1;
        } else {
            if (a.price == a.price) {
                return 0;
            } else {
                return 1;
            }
        }
    }

    public static int PriceGiamdan(Book a, Book b) {
        if (a.price > b.price) {
            return -1;
        } else {
            if (a.price == a.price) {
                return 0;
            } else {
                return 1;
            }
        }
    }

    @Override
    public String toString() {
        return name + " by" + Arrays.toString(id_Authors) + " price is " + price + "$" + " with " + count + " books";
    }

    public String TOSTRING() {
        return name + " by" + Arrays.toString(id_Authors) + " price is " + price + "$";
    }
}
