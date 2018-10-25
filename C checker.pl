use strict;

my $badfound = 0;
sub check_line {
    my($fn, $line) = @_;

   
    if($line =~ /^\s*if\s*\(.*[^!<>=]=([^=].*\)|\))/) {
        if(!$badfound) {
            print("The following suspicious lines were found:\n");
            $badfound = 1;
        }
        print "$fn:$.: $line\n";
    }
}



sub check_file {
    my($fn) = @_;

    if(!open(IN, $fn)) {
        print "Cannot read $fn.\n";
        return;
    }

    my($line);
    while($line = <IN>)
    {
        chomp $line;
        check_line($fn,$line);
    }

    close IN;
}


while(my $fn = shift @ARGV) {
    check_file($fn);
}
if(!$badfound) { print "No suspicious lines were found.\n"; }
