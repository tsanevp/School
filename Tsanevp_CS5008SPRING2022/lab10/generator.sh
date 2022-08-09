# System Report Generator

TITLE="System Information Report for $HOSTNAME"
CURRENT_TIME=$(date +"%x %r %Z")
TIME_STAMP="Generated $CURRENT_TIME, by $USER"
USER_DIR=~/home/$USER

report_uptime(){
    echo "
        <H2>System Uptime</H2>
        <PRE>$(uptime)</PRE>"
    return
}

report_disk_space(){
    echo "
        <H2>Disk Space</H2>
        <PRE>$(df -h)</PRE>"
    return
}

report_mem_usage() {
    echo "
        <H2>Top Memory Space Usage</H2>
        <PRE>$(top -o %MEM | head -n 15)</PRE>"
    return
}

list_history() {
    echo "
        <H2>History of last 10 commands used:</H2>
        <PRE>$(history | tail)</PRE>"
}

echo "<HTML>
<HEAD>
    <TITLE>$TITLE</TITLE>
</HEAD>
<BODY>
    <H1>$TITLE</H1>
    <P>$TIME_STAMP</P>
    <P>$(report_uptime)</P>
    <P>$(report_disk_space)</P>
    <P>$(report_mem_usage)</P>
    <P>$(list_history)</P>
</BODY>

<HTML>"
