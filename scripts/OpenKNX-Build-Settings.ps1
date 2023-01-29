
# set product names, allows mapping of (devel) name in Project to a more consistent name in release
$settings = lib/OGM-Common/scripts/build/OpenKNX-Build-Settings.ps1 $args[0] "TAS-UP-8xLJ" "TAS-UP-8xLJ"

$settings.sourceName="TAS-UP-8xLJ"  
$settings.targetName="TAS-UP-8xLJ" 
$settings.knxprod="src/{0}Knxprod.h" -f $settings.sourceName
$settings.hardware="src/{0}Hardware.h" -f $settings.sourceName

Return $settings