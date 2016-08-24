(function($) {
    //Drupal.behaviors.wishlist = {
    //    attach: function (context, settings) {
    //      $(document).ready(function () {
    //            $('#main-menu-links li a:contains("Wishlist")').mouseover(function() {
    //                $('#top_wishlist').show();
    //                //$.ajax({
    //                //  url: settings.wishlist.path + "/ajax/get_top_wishlist.php",
    //                //  type: "POST",
    //                //  data:{user_id:settings.wishlist.uid},
    //                //  success:function() {
    //                //    $('body').append();
    //                //  },
    //                //});
    //            }).mouseleave(function() {
    //               $('#top_wishlist').hide();
    //        });
    //    }
    //};
    
    $(document).ready(function () {
        var container =  $('#top_wishlist');
        $('#main-menu-links li a:contains("Wishlist")').hover(function(){
            //container.show();
            //function () {
            //    container.stop(true,true).show();
            //}, 
            //function () {
            //     container.stop(true,true).hide();
        });
        
                
        //$('#top_wishlist').show();
            //$.ajax({
            //  url: settings.wishlist.path + "/ajax/get_top_wishlist.php",
            //  type: "POST",
            //  data:{user_id:settings.wishlist.uid},
            //  success:function() {
            //    $('body').append();
            //  },
            //});
        //}).mouseleave(function() {
        //    $('#top_wishlist').hide();
        //    $('#top_wishlist').focus(function(){
        //        alert(1);
        //    });
        //});
        
                
        
    });    
})(jQuery);