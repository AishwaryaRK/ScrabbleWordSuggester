class odometer{
	private static final int MAX = 10;	
	private static final int LARGEST = 123456789;	
	private static boolean isValidValue(int odoValue) {
		int previous = MAX;
		for ( ;  odoValue > 0;  odoValue /= 10) {
			if ( odoValue % 10 < previous ) {
				previous = odoValue % 10;
			}
			else {
				return false;
			}
		}
		return true;
	}
	
	private static int getNextReading(int currentValue,int numDigits) {
	 
		if(currentValue==(LARGEST%Math.pow(10,numDigits))){
	
			return (int)(LARGEST/Math.pow(10,9-numDigits));
		}
		while(!isValidValue(currentValue+1)){
			currentValue++;
		}
	
		return currentValue+1;
	}

	private static int getPreviousReading(int currentValue,int numDigits){
		if(currentValue==LARGEST/Math.pow(10,9-numDigits)){
			return (int)(LARGEST%Math.pow(10,numDigits));
		}
		while(!isValidValue(currentValue-1)){
			currentValue--;
		}
		return currentValue-1;
	}

	private static int getDistanceBetweenTwoDigits(int startReading , int endReading,int numDigits){
		int distance = 0 ;
		while(startReading<=endReading){
		    startReading = getNextReading(startReading,numDigits);
			distance++;
		
		}
			return distance;
	}


	
	
	public static void main(String args[]){
		//BufferedReader in = new BufferedReader(System.in);
		//System.out.printl	
		int reading = 1234;
		int nextReading = 3567;
		System.out.println(getNextReading(reading,4));
		System.out.println(getPreviousReading(reading,4));
		System.out.println(getDistanceBetweenTwoDigits(reading,nextReading,4));
	
	
	}	
	
}