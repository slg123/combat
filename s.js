var a = []; 
var N = 2000000;
for ( var i = 2; i <= N; i++ ) {
    a[i] = 1; 
}

a[1] = 0;
for ( var j = 2; j <= N/2; j++ ) {
    for ( var k = 2; k <= N/j; k++ ) {
        a[j*k] = 0;
    }
}

var sum = 0;
for ( var n = 1; n <= 2000000; n++ ) {
    if ( a[n] ) {
        sum += n;
    }
}
document.write( sum ); 
