// On hover render vulf icon
// Run when page is loaded
$(document).ready(() => 
{
    //  Select every <a> tag
    $("span").on("mouseenter", function() 
    {
        // On mouse enter change color
        $(this).css("color", "red");
    }).on("mouseleave", function()
    {
        // On mouse leave change color back
        $(this).css("color", "black");
    });

    $("header").on("mouseenter", function() 
    {
        // On mouse enter change color
        $(".vulf_dash").css("visibility", "visible");
    }).on("mouseleave", function()
    {
        // On mouse leave change color back
        $(".vulf_dash").css("visibility", "hidden");
    });
});
