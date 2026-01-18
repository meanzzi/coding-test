#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int x){
    if(x < 2) return false;
    else 
        for(int i = 2; i*i<=x; i++){
            if(x%i == 0) return false;
        }
    return true;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    for(size_t i=0; i<nums_len; i++){
        for(size_t j=i+1; j<nums_len; j++){
            for(size_t k=j+1; k<nums_len; k++){
                int sum = nums[i]+nums[j]+nums[k];
                if(isPrime(sum)) answer++;              
            }
        }
    }
    
    return answer;
}