#include <iostream> // Use the iostream library.
#include <string> // Use the string library.
#include <vector> // Use the vector library.
using namespace std; // Because we do not have to repeat this in every line.
struct commodity // Definition of product struct including name, price, stock and category.
{
    string name; // Name of commodity
    float price; // Price of commodity
    int stock; // Stock of commodity
    string category; // Category of commodity
};
vector<commodity> goods; // Using dynamic vectors to store products
double balance_m=1000; // Define the customer's wallet and putting 1000 into it.
double balance_sh=0; // Define the manager(shop)'s wallet and putting 0 into it.
class mangare // Class of manager...
{
    public: // Public access...
    	void add_commodity() // Add product function.
    	{
    		commodity new_commodity; // New product definition.
    		cout << "Enter commodity name: "; // Ask for product name.
    		cin >> new_commodity.name; // Get product name.
    		cout << endl << "Enter commodity price: "; // Ask for product price.
    		cin >> new_commodity.price; // Get product price.
    	    cout << endl << "Enter commodity stock: "; // Ask for product stock.
    	    cin >> new_commodity.stock; // Get product stock.
    	    cout << endl << "Enter commodity category: "; // Ask for product category.
    	    cin >> new_commodity.category; // Get product category.
    		goods.push_back(new_commodity); // Add product to vector.
    	    cout << "You have seccessfully added the commodity!"; // Show the seccessfully masage.
		}
		void remove_commodity() // Product remove function.
		{
			string name; // Name of the product we want to delete.
			cout << "Enter the name of the commodity you want to delete." << endl; // Asking for the name of the desired product.
			cin >> name; // Getting for the name of the desired product.
			for (int i=0 ;i< goods.size()-1; i++) // Loop to search for the desired product.
			{
				if (goods[i].name==name) // Provided that the product is the one we are looking for.
				{
					for (int j=i; j< goods.size()-1 ; j++) // Moves product back one by one (replaces the deleted product).
					{
						goods[j]=goods[j+1];
					}
					cout << "The commodity was seccessfully deleted." << endl; // Show the seccessfully message.
					return;
				}
			}
			else
            {
                cout << "The commodity is not founded." << endl; // If the product is not among the store's products, it will say "Not found".
            }
		}
		void search_commodity() // Searched for the product.
		{
			string name; // The name of the product we are looking for.
			cout << "Whats commodity are you loking for?" << endl; // Asking for the name of the product we are looking for.
			cin >> name; // Getting the name of the product we are looking for.
			for (int i=0; i< goods.size() ; i++) // The loop for looking for product.
			{
				if (goods[i].name==name) // Check whether this product is the desired product or not.
				{
					cout << "Commodity specifications: " << endl; // show the specifications of product we looking for.
					cout << "Name: " << goods[i].name << endl; // Show the name of the product.
					cout << "Price: " << goods[i].price << endl; // Show the price of the product.
					cout << "Stock: " << goods[i].stock << endl; // Show the stock of the product.
					cout << "Category: " << goods[i].category << endl; // Show the category of the product.
					return;
				}
			}
			cout << "The commodity is not founded." << endl; // if we can't found product.
		}
		void display_commodity() // Product list display function.
		{
			if (goods.size() ==0) // If we didn't have a product.
			{
				cout << "No commodity in the shop!" << endl; // Show we didn't have any  product.
				return;
			}
			else // If we had product.
			{
				cout << "List of all commodity:" << endl; // Display the list of available product.
				for (int i=0; i< goods.size() ; i++) // Loop for display the list of available product.
				{
					cout << "Name: " << goods[i].name << endl; // Show the name of product.
					cout << "Price: " << goods[i].price << endl; // Show the price of product.
					cout << "Stock: " << goods[i].stock << endl; // Show the stock of product.
					cout << "Category: " << goods[i].category << endl; // show the category of product.
                    // This loop shows each product and all their features.
				}
			}
		}
		void calculateTotalValue() // Function to calculate the total value of store goods.
		{
			float totalValue= 0.0f; // Define a variable to store the value of all goods.
			for (int i=0; i< goods.size() ; i++) // This loop goes through the list of products one by one and calculates their value.
			{
				totalValue+= goods[i].price * goods[i].stock; // The value of each item is multiplied by its stock and aded to the final amount.
			}
			cout << "The total value of the goods in the store: " << totalValue << endl; // Display the result.
		}
		void Balance_sh() // Store wallet display function.
		{
			cout << "Your wallet balance: " << balance_sh << endl; // Display the store wallet.
		}
		void addToBalance_sh() // Add the store wallet function.
		{
			float amount_sh; // Define a variable to store the value we want to add.
			cout << "How much do you want to top up your account?" << endl; // Asking for a variable to store the value we want to add.
			cin >> amount_sh; // Getting a variable to store the value we want to add.
			if (amount_sh>0) // Checking if a number is not negative.
			{
				balance_sh += amount_sh; // Add to wallet.
				cout << "Your wallet has been successfully charged to " << amount_sh << '.' << endl; // Show the seccessfully message.
			}
			else // If the input is negative.
			{
				cout << "The entered value is not correct!" << endl; // Show error.
			}
			Balance_sh(); // Show the amount in the wallet.
		}
        void menu1() // Menu function for admin.
        {
            int choice; // Define a variable for user selection.
            customer buyer; // Define an object of class customer named buyer.
            do 
            {
                cout << "Goods inventory menu" << endl; // Show menu.
                cout << "1. Add a commodity. " << endl;
                cout << "2. Delete a commodity." << endl;
                cout << "3. Search a commodity." << endl;
                cout << "4. Show goods." << endl;
                cout << "5. Calculation of the total value of the inventory." << endl;
                cout << "6. Store wallet inventory. " << endl;
                cout << "7. Store wallet charging. " << endl;
                cout << "8. Go to the customer menu. " << endl;
                cout << "0. Exit" << endl;
                cout << "Please enter your choice: "; // Asking for choice.
                cin >> choice; // Getting choice.
                switch (choice)
                {
            	    case 1:
            	    	add_commodity(); // Run the add product function.
            		    break;
            	    case 2:
            		    remove_commodity(); // Run the remove product function.
            		    break;
            	    case 3:
            		    search_commodity(); // Run the search commodity function.
            		    break;
            	    case 4:
            		    display_commodity(); // Run the display commodity function.
            		    break;
                 	case 5:
            	    	calculateTotalValue(); // Run the calculate total value function.
            	      	break;
            	    case 6:
            	    	Balance_sh(); // Run the balance shop function.
            	    	break;
                	case 7:
            	    	addToBalance_sh(); // Run the add to balance shop function.
            		    break;
            	    case 8:
            		    buyer.menu2(); // go to buyer menu. Run the menu2 function in the class customer.
            		    break;
            	    case 0:
            		    cout << "Exit" << endl; // exit the app.
            	    default:
            		    cout << "The option is invalid!" << endl; // This is not a correct choice.
               }
            }
			while (choice!=0)
        }
};
class customer // class of customer...
{
	public: // Public access...
	    void search_commodity() // Searched for the product.
	        {
		        string name; // The name of the product we are looking for.
		        cout << "Whats commodity are you loking for?" << endl; // Asking for the name of the product we are looking for.
		        cin >> name; // Getting the name of the product we are looking for.
		        for (int i=0; i< goods.size() ; i++) // The loop for looking for product.
		        {
			        if (goods[i].name==name) // Check whether this product is the desired product or not.
			        {
				        cout << "Commodity specifications: " << endl; // show the specifications of product we looking for.
				        cout << "Name: " << goods[i].name << endl; // Show the name of the product.
				        cout << "Price: " << goods[i].price << endl; // Show the price of the product.
				        cout << "Stock: " << goods[i].stock << endl; // Show the stock of the product.
				        cout << "Category: " << goods[i].category << endl; // Show the category of the product.
				        return;
			        }
		        }
		        cout << "The commodity is not founded." << endl; // if we can't found product.
	        }
		void display_commodity() // Product list display function.
		{
			if (goods.size() ==0) // If we didn't have a product.
			{
				cout << "No commodity in the shop!" << endl; // Show we didn't have any  product.
				return;
			}
			else // If we had product.
			{
				cout << "List of all commodity:" << endl; // Display the list of available product.
				for (int i=0; i< goods.size() ; i++) // Loop for display the list of available product.
				{
					cout << "Name: " << goods[i].name << endl; // Show the name of product.
					cout << "Price: " << goods[i].price << endl; // Show the price of product.
					cout << "Stock: " << goods[i].stock << endl; // Show the stock of product.
					cout << "Category: " << goods[i].category << endl; // show the category of product.
					// This loop shows each product and all their features.
				}
			}
		}
		void shopping_cart() // Defining a function for the shopping cart.
		{
            string name; //
            int h; // A variable to store the number of item the user wants to buy.
            cout << "how many items do you want to buy?"; // Asking for the number of item the user wants to buy.
            cin >> h; // Gettig the number of item the user wants to buy.
            if (h<=0 || h> goods.size ) // Checking whether the entered value is incorrect.
            {
            	cout << "invalid number of items." << endl; // Show message "The number you enter is not correct".
            	return;
			}
			else // Check the correctness of the entered value.
			{
				vector<string> arr(h); // Define vector for the goods customer wants to buy.
				display_commodity(); // Run display commodity function.
				float sum=0.0f; // Define variable to store the amount of money the customer must pay.
				for (int i=0; i<h; i++) // 
				{
					cout << "please enter a name of the commodity you want to buy: " << endl;
					cin >> arr[i];
					bool found = false;
					for (int j=0; j< goods.size() ; j++)
					{
						if (goods[j].name==arr[i])
						{
							sum+= goods[j].price;
							found= true;
							break;
						}
					}
					if (!found)
					{
						cout << arr[i] << "not found in inventory." << endl;
					}
				}
			}
			for (int j=0; j<h; j++)
			{
				cout << "all preachers: " << sum << endl;
			}
		}
		void addToBalance_m()
		{
			float amount_m;
			cout << "how much do you want to top up your account?" << endl;
			cin >> amount_m;
			if(amount_m>0)
			{
				balance_m += amount_m;
				cout << "your wallet has been succesfully charged to" << amount_m << '.' << endl;
			}
			else
			{
				cout << "the entered value is not correct!" << endl;
			}
			Balance_m();
		}
		void Balance_m()
		{
			cout << "your wallet balance: " << balance_m << endl;
		}
		void products_by_category()
		{
			cout << "categories available: " << endl;
			cout << "1. game" << endl << "2. console" << endl << "3. monitor" << "4. headset" << endl;
			cout << "Enter the category number you want please: ";
			int w;
			cin >> w;
			switch (w)
			{
				case 1:
					cout << "games" << endl;
					for (int i=0; i< goods.size() ; i++)
					{
						if (goods[i].category== "game")
						{
							cout << goods[i].name << endl;
						}
					}
					break;
				case 2:
					cout << "consol" << endl;
					for (int i=0; i< goods.size() ; i++)
					{
						if (goods[i].category== "console")
						{
							cout << goods[i].name << endl;
						}
					}
					break;
				case 3:
					cout << "monitor" << endl;
					for (int i=0; i<goods.size(); i++)
					{
						if (goods[i].category== "monitor")
						{
							cout << goods[i].name << endl;
						}
					}
					break;
				case 4:
					cout << "headset" << endl;
					for (int i=0; i< goods.size() ; i++)
					{
						if (goods[i].category== "headset")
						{
							cout << goods[i].name << endl;
						}
					}
					break;
			} 
		}
		void menu2 ()
		{
			int choice;
			customer admin;
			do
			{
				cout << "goods inventory menu:" << endl;
				cout << "1. search a commodity." << endl;
				cout << "2. show goods." << endl;
				cout << "3. top up wallet." << endl;
				cout << "4. balance of money in user account." << endl;
				cout << "5. shopping cart." << endl;
				cout << "6. show products by category." << endl;
				cout << "7. go to the admin menu." << endl;
				cout << "0.exit" << endl;
				cout << "please enter your choice:" << endl;
				cin >> choice;
				string pass;
				switch (choice)
				{
					case 1:
						search_commodity();
						break;
					case 2:
						display_commodity();
						break;
					case 3:
						add_ToBalance_m();
						break;
					case 4:
						Balance_m();
						break;
					case 5:
						shopping_cart();
						break;
					case 6:
						products_by_category();
						break;
					case 7:
						cout << "Please enter the password: ";
			            cin >> pass;
			            if (pass == pass_add)
			            {
				            admin.menu1();
		            	}
				        break;
					case 0:
						cout << "exit" << endl;
						break;
					default:
						cout << "the option is invalid!" << endl;
				}
			}
		}
};
int main()
{
	mangare admin;
	customer buyer;
	int q;
	cout << "Hi welcome to our site!" << endl << "Please enter your user mode from the options: " << endl << "If you are a customer, enter the number 1." << endl << "If you are a administration, enter number 2." << endl;
	cin >> q;
	switch (q)
	{
		case 1:
			string pass;
			string pass_add ="admin1admin";
			cout << "Please enter the password: ";
			cin >> pass;
			if (pass== pass_add)
			{
				admin.menu1();
			}
			else
			{
				cout << "False password!" << endl;
				return 0;
			}
			break;
		case 2:
			buyer.menu2();
			break;
		default:
			cout << "Please enter the correct answer!" << endl;
	}
	return 0;
}