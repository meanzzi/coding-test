function solution(sizes) {    
    let maxW = 0, maxH = 0;
    
    for(let i=0; i<sizes.length; i++){
        sizes[i].sort((a,b)=> a-b);
        
        if(sizes[i][0] > maxW) maxW = sizes[i][0];
        if(sizes[i][1] > maxH) maxH = sizes[i][1];
    }
    return maxW * maxH;
}