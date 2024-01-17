#include <stdio.h>
#include <string.h>

// Function declaration
double fetchSubAmount(int quantityA, int quantityB, int quantityC);
char* discountApplied(double subTotal, int total_quantity, int quantityA, int quantityB, int quantityC);
double getDeduction(char* fetchDiscount, double subTotal, int quantityA, int quantityB, int quantityC);
void displayReceipt(double amtToPaid, double totalAmtDeduction, double shippingFee, char* fetchDiscount, double subTotal, int quantityA, int quantityB, int quantityC, int giftPrice);

int main() {
    int quantity_A = 0;
    int quantity_B = 0;
    int quantity_C = 0;
    int gift_Price = 0;

    // ProductA Input
    do {
        printf("Enter Quantity For Product A: ");
        scanf("%d", &quantity_A);

        while (1) {
            printf("Want To Wrap As A Gift Press Y for yes and N for No: ");
            char giftWrap;
            scanf(" %c", &giftWrap);

            if (giftWrap == 'y' || giftWrap == 'Y') {
                gift_Price = quantity_A;
                break;
            } else if (giftWrap == 'n' || giftWrap == 'N') {
                break;
            }
            printf("Wrong Input\n");
        }

        if (quantity_A < 0) {
            printf("Quantity cannot be in negative !!\n");
        }
    } while (quantity_A < 0);

    // ProductB Input
    do {
        printf("Enter Quantity For Product B: ");
        scanf("%d", &quantity_B);

        while (1) {
            printf("Want To Wrap As A Gift Press Y for yes and N for No: ");
            char giftWrap;
            scanf(" %c", &giftWrap);

            if (giftWrap == 'y' || giftWrap == 'Y') {
                gift_Price += quantity_B;
                break;
            } else if (giftWrap == 'n' || giftWrap == 'N') {
                break;
            }
            printf("Wrong Input\n");
        }

        if (quantity_B < 0) {
            printf("Quantity cannot be in negative !!\n");
        }
    } while (quantity_B < 0);

    // ProductC Input
    do {
        printf("Enter Quantity For Product C: ");
        scanf("%d", &quantity_C);

        while (1) {
            printf("Want To Wrap As A Gift Press Y for yes and N for No: ");
            char giftWrap;
            scanf(" %c", &giftWrap);

            if (giftWrap == 'y' || giftWrap == 'Y') {
                gift_Price += quantity_C;
                break;
            } else if (giftWrap == 'n' || giftWrap == 'N') {
                break;
            }
            printf("Wrong Input\n");
        }

        if (quantity_C < 0) {
            printf("Quantity cannot be in negative !!\n");
        }
    } while (quantity_C < 0);

    // Main Logic
    int total_quantity = quantity_A + quantity_B + quantity_C;
    double subTotal = fetchSubAmount(quantity_A, quantity_B, quantity_C);
    char* fetchDiscount = discountApplied(subTotal, total_quantity, quantity_A, quantity_B, quantity_C);
    double totalAmtDeduction = getDeduction(fetchDiscount, subTotal, quantity_A, quantity_B, quantity_C);
    totalAmtDeduction = subTotal - totalAmtDeduction;
    double shippingFee = (double)(total_quantity * 5) / 10;
    double amtToPaid = totalAmtDeduction + shippingFee + gift_Price;

    // Output
    displayReceipt(amtToPaid, totalAmtDeduction, shippingFee, fetchDiscount, subTotal, quantity_A, quantity_B, quantity_C, gift_Price);

    return 0;
}


double fetchSubAmount(int quantityA, int quantityB, int quantityC) {
    int total_Amt = quantityA * 20;
    total_Amt += quantityB * 40;
    total_Amt += quantityC * 50;
    return total_Amt;
}

char* discountApplied(double subTotal, int total_quantity, int quantityA, int quantityB, int quantityC) {
    if (total_quantity > 30 && (quantityA > 15 || quantityB > 15 || quantityC > 15))
        return "tiered_50_discount";
    else if (total_quantity > 20)
        return "bulk_10_discount";
    else if (quantityA > 10 || quantityB > 10 || quantityC > 10)
        return "bulk_5_discount";
    else if (subTotal > 200)
        return "flat_10_discount";
    return "Discount Not Applicable";
}

double getDeduction(char* fetchDiscount, double subTotal, int quantityA, int quantityB, int quantityC) {
    if (strcmp(fetchDiscount, "flat_10_discount") == 0) {
        return 10;
    } else if (strcmp(fetchDiscount, "bulk_5_discount") == 0) {
        double deduction = 0;
        if (quantityA > 10) {
            deduction += (((double)(quantityA * 20) / 100) * 5);
        }
        if (quantityB > 10) {
            deduction += (((double)(quantityB * 40) / 100) * 5);
        }
        if (quantityC > 10) {
            deduction += (((double)(quantityC * 50) / 100) * 5);
        }
        return deduction;
    } else if (strcmp(fetchDiscount, "bulk_10_discount") == 0)
        return (subTotal * 10) / 100;
    else if (strcmp(fetchDiscount, "tiered_50_discount") == 0) {
        double deduction = 0;
        if (quantityA > 15)
            deduction += (double)(quantityA * 20) / 2;
        if (quantityB > 15)
            deduction += (double)(quantityB * 40) / 2;
        if (quantityC > 15)
            deduction += (double)(quantityC * 50) / 2;
        return subTotal - deduction;
    } else
        return 0;
}

void displayReceipt(double amtToPaid, double totalAmtDeduction, double shippingFee, char* fetchDiscount, double subTotal, int quantityA, int quantityB, int quantityC, int giftPrice) {
    printf("\nReceipt Cum Bill\n");
    printf("Product A, Quantity = %d, Total Amt: %d\n", quantityA, quantityA * 20);
    printf("Product B, Quantity = %d, Total Amt: %d\n", quantityB, quantityB * 40);
    printf("Product C, Quantity = %d, Total Amt: %d\n", quantityC, quantityC * 50);
    printf("Sub Total: %f\n", subTotal);
    printf("Discount Applied: %s\nAmt After Discount: %f\n", fetchDiscount, totalAmtDeduction);
    printf("Shipping Fee: %f\nGift Wrap Fee: %d\n", shippingFee, giftPrice);
    printf("Total Amt To Be Paid: %f\n", amtToPaid);
}