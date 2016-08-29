<?php


function wishlist_add_item($pid) {
  $page = array();
  
  global $user;
  
  $nid = db_insert('wishlist') // Table name no longer needs {}
    ->fields(array(
      'pid' => $pid,
      'uid' => $user->uid,
      'created' => REQUEST_TIME,
      'weight' => -10
    ))
    ->execute();
  drupal_goto('node/'. $pid);
  return $page;
}
