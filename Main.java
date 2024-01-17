import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        int quantity_A = 0;
        int quantity_B = 0;
        int quantity_C = 0;

        int gift_Price = 0;

        Scanner sc = new Scanner(System.in);
        //ProductA Input
        do {
            System.out.println("Enter Quantity For Product A:");
            quantity_A = sc.nextInt();
            while (true) {
                System.out.println("Want To Wrap As A Gift Press Y for yes and N for No: ");
                String giftWrap = sc.next().toLowerCase();
                if (giftWrap.equals("y")) {
                    gift_Price = quantity_A;
                    break;
                } else if (giftWrap.equals("n")) {
                    break;
                }
                System.out.println("Wrong Input: ");
            }
            if(quantity_A < 0)
                System.out.println("Quantity cannot be in negative !! ");
        }while (quantity_A < 0);

        //ProductB Input
        do {
            System.out.println("Enter Quantity For Product B:");
            quantity_B = sc.nextInt();
            while (true) {
                System.out.println("Want To Wrap As A Gift Press Y for yes and N for No: ");
                String giftWrap = sc.next().toLowerCase();
                if (giftWrap.equals("y")) {
                    gift_Price += quantity_B;
                    break;
                } else if (giftWrap.equals("n"))
                    break;
                System.out.println("Wrong Input: ");
            }
            if(quantity_B < 0)
                System.out.println("Quantity cannot be in negative !! ");
        }while (quantity_B < 0);
        //ProductC Input
        do {
            System.out.println("Enter Quantity For Product C:");
            quantity_C = sc.nextInt();
            while (true) {
                System.out.println("Want To Wrap As A Gift Press Y for yes and N for No: ");
                String giftWrap = sc.next().toLowerCase();
                if (giftWrap.equals("y")) {
                    gift_Price += quantity_C;
                    break;
                } else if (giftWrap.equals("n"))
                    break;
                System.out.println("Wrong Input: ");
            }
            if(quantity_C < 0)
                System.out.println("Quantity cannot be in negative !! ");
        }while (quantity_C < 0);



        //Main Logic
        int total_quantity = quantity_A+quantity_B+quantity_C;
        double subTotal = fetchSubAmount(quantity_A,quantity_B,quantity_C);
        String fetchDiscount = discountApplied(subTotal,total_quantity,quantity_A,quantity_B,quantity_C);
        double totalAmtDeduction = getDeduction(fetchDiscount,subTotal,quantity_A,quantity_B,quantity_C);
        totalAmtDeduction = subTotal - totalAmtDeduction;
        double shippingFee = (double) (total_quantity * 5)/10;
        double amtToPaid =  totalAmtDeduction + shippingFee + gift_Price;


        //Output
        displayReceipt(amtToPaid,totalAmtDeduction,shippingFee,fetchDiscount,subTotal,quantity_A,quantity_B,quantity_C,gift_Price);

    }

    private static void displayReceipt(double amtToPaid,double totalAmtDeduction, double shippingFee, String fetchDiscount, double subTotal, int quantityA, int quantityB, int quantityC, int giftPrice) {

        System.out.println("\nReceipt Cum Bill");
        System.out.println("Product A ,Quantity = "+quantityA+" Total Amt  : "+quantityA*20);
        System.out.println("Product B ,Quantity = : "+quantityB+" Total Amt  : "+quantityB*40);
        System.out.println("Product C ,Quantity = : "+quantityC+" Total Amt  : "+quantityC*50);
        System.out.println("Sub Total: "+subTotal);
        System.out.println("Discount Applied : "+fetchDiscount+"\nAmt After Discount : "+totalAmtDeduction);
        System.out.println("Shipping Fee : "+shippingFee+"\n Gift Wrap Fee "+giftPrice);
        System.out.println("Total Amt To Be Paid : "+amtToPaid);
    }

    private static double getDeduction(String fetchDiscount, double subTotal, int quantityA, int quantityB, int quantityC) {

    if(fetchDiscount.equals("flat_10_discount"))
    {
        return 10;
    }
    else if (fetchDiscount.equals("bulk_5_discount"))
    {
        double deduction = 0;
           if(quantityA > 10)
           {
               deduction  +=  (((double) (quantityA * 20) /100)*5);
           }
           if (quantityB > 10) {
               deduction += (((double) (quantityB * 40) /100)*5);
           }
           if(quantityC > 10)
           {
               deduction +=(((double) (quantityC * 50) /100)*5);
           }
           return deduction;
    } else if (fetchDiscount.equals("bulk_10_discount"))
            return (subTotal * 10)/100;
      else if (fetchDiscount.equals("tiered_50_discount")) {

        double deduction = 0;
     if(quantityA > 15)
         deduction += (double) (quantityA * 20) /2;
     if(quantityB > 15)
         deduction += (double) (quantityB * 40) /2;
     if(quantityC >15)
            deduction += (double)(quantityC*50)/2;
     return subTotal - deduction;
    }else
        return 0;
    }

    private static String discountApplied(double subTotal, int total_quantity, int quantityA, int quantityB, int quantityC) {
        if(total_quantity > 30 &(quantityA > 15 || quantityB > 15 || quantityC > 15))
            return "tiered_50_discount";
        else if(total_quantity > 20)
         return "bulk_10_discount";
        else if(quantityA > 10 || quantityB > 10 || quantityC > 10)
            return "bulk_5_discount";
        else if (subTotal > 200)
         return "flat_10_discount";
       return "Discount Not Applicable ";
    }

    private static double fetchSubAmount(int quantityA, int quantityB, int quantityC) {
    int total_Amt = quantityA * 20;
    total_Amt += quantityB * 40;
    total_Amt += quantityC * 50;
    return total_Amt;
    }
}