package SellingBook;

import java.util.ArrayList;
import java.util.Collections;

public class Cart {

    public ArrayList<Book> listBook;//tao gio hang
    public double total;//tinh tien

    public Cart() {
        //tao moi 1 mang
        listBook = new ArrayList<>();
    }

    public ArrayList<Book> getCart() {
        return listBook;
    }

    public Book getBookfromList(int i) {
        //lay them sach bo vao gio neu con sach
        if (i >= 0 && i < listBook.size()) {
            int t = listBook.get(i).getAmount();
            int r = listBook.get(i).getCount();
            if (t >= 1) {
                t--;
                r++;
                listBook.get(i).setCount(r);
                listBook.get(i).setAmount(t);
                System.out.println("U gets a book: " + listBook.get(i).TOSTRING());
                return listBook.get(i);
            } else {
                System.out.println("Out of books");
            }
        }
        //khong co sach
        return null;
    }

    public void setBookfromList(String namebook) {
        //sua thong tin 1 cuon sach
        for (Book a : listBook) {
            if (a.getName().compareToIgnoreCase(namebook) == 0) {
                a.getInfo();
            }
        }
    }

    public void addBookNameToCart(String namebook, Cart GioHang) {
        //tim sach bo vao gio
        for (Book a : listBook) {
            if (a.getName().compareToIgnoreCase(namebook) == 0) {
                int r = a.getCount();
                r++;
                a.setCount(r);
                GioHang.addBookToCart(a);
            }
        }
    }

    public void deleteBookfromCart(String namebook, Cart giohang) {
        //xoa sach trong gio hang vi 1 ly do nao do...
        for (Book a : listBook) {
            if (a.getName().compareToIgnoreCase(namebook) == 0) {
                int r = a.getCount();
                r = 0;
                a.setCount(r);
                giohang.listBook.remove(a);
            }
        }
    }

    public boolean addBookToCart(Book book) {
        //them du lieu sach vao ke hang
        //neu trong ke hang chua sach do thi khong lay thong tin
        if (listBook.contains(book)) {
            return false;
        } //neu khong co thi lay sach do
        else {
            listBook.add(book);
        }
        return true;
    }

    public void displayCart() {
        //hien thi danh sach gio hang
        System.out.println("List of book in your cart:");
        //cac cuong sach duoc in ra
        listBook.forEach(
                a -> {
                    System.out.println(a.toString());
                }
        );
    }

    public void deleteAll() {
        //lay cho da r khong mua ?? :D ??
        listBook.forEach(
                a -> {
                    a.setCount(0);
                }
        );
        listBook.removeAll(listBook);
    }

    public void calTotal() {
        //tinh tien trong gio hang
        total = 0;
        listBook.forEach(
                a -> {
                    total = total + a.getPrice() * a.getCount();
                }
        );
    }

    public int countBook() {
        total = 0;
        listBook.forEach(
                a -> {
                    total = total + a.getCount();
                }
        );
        double s = total;
        return (int) s;
    }

    public void sortbyName(int k) {
        //sap xep theo ten sach tu a-z
        if (k == 0) {
            Collections.sort(listBook, Book::NameTangdan);
        } //tu z-a
        else {
            Collections.sort(listBook, Book::NameGiamdan);
        }
    }

    public void sortbyPrice(int k) {
        //sap xep theo gia tien tu nho toi lon
        if (k == 0) {
            Collections.sort(listBook, Book::PriceTangdan);
        } //tu lon toi nho
        else {
            Collections.sort(listBook, Book::PriceGiamdan);
        }
    }
}
