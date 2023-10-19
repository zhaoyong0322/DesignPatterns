#include "meal.h"

class MealBuilder
{
public:
    Meal *prepareVegMeal ()
    {
      Meal * meal = new Meal();
      meal->addFoodToVector(new VegBurger());
      meal->addFoodToVector(new Coke());
      return meal;
   }
   Meal *prepareNonVegMeal ()
   {
      Meal * meal = new Meal();
      meal->addFoodToVector(new ChickenBurger());
      meal->addFoodToVector(static_cast<ColdDrink *>(new Pepsi()));
      return meal;
   }
};


void builder_test() {

    MealBuilder * mealBuilder = new MealBuilder();
    Meal * vegMeal = mealBuilder->prepareVegMeal();
    cout << "Veg Meal" << endl;
    vegMeal->showFoods();
    cout << "Total Cost: " << vegMeal->getCost() << endl;
    Meal * nonVegMeal = mealBuilder->prepareNonVegMeal();
    cout << "\n\nNon-Veg Meal" << endl;
    nonVegMeal->showFoods();
    cout << "Total Cost: " << nonVegMeal->getCost() << endl;

}
