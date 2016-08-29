<?php


function wishlist_delete_item($item_id) {
  $page = [];
  
   db_delete('wishlist')
      ->condition('id', $item_id)
      ->execute();
  
  drupal_goto('wishlist');
  
  return $page;
}
