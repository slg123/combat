var a = []; 
var N = 2000000;
for ( var i = 2; i <= N; i++ ) {
    a[i] = 1; 
}

a[1] = 0;
for ( var i = 2; i <= N/2; i++ ) {
    for ( var j = 2; j <= N/i; j++ ) {
        a[i*j] = 0;
    }
}

var sum = 0;
for ( var i = 1; i <= 2000000; i++ ) {
    if ( a[i] ) {
        sum += i;
    }
}
document.write( sum ); 
