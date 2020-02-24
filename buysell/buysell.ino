float buyprice;
String inputbuy;
float profit;
String inputprof;
float sellprice;

void setup(){
  Serial.begin(9600);
  Serial.println("Enter Buying Price:");
}

void loop(){
  delay(500);
  if(Serial.available() > 0){
    inputbuy = Serial.readString();
    buyprice = inputbuy.toFloat();
    Serial.print("Buyprice: ");
    Serial.println(buyprice);
    Serial.print("Enter Profit Desired:");
  }
  delay(500);
  if(Serial.available() > 0){
    inputprof = Serial.readString();
    profit = inputprof.toFloat();
    Serial.println("Profit: ");
    Serial.println(profit);
    sellprice = buyprice + (buyprice * .005) + profit;
    Serial.print("Sell at: $");
    Serial.println(sellprice);
  }
}
