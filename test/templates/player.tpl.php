<div class="player">
  <div class="name"><?php echo t('Player name'). ': '. $name; ?></div>
  <div class="picture">
    <img style="width:100px;"  src="<?php echo $picture; ?>">
  </div>
  <div class="number">
    <span><?php echo t('Number'). ': '; ?> </span>
    <?php echo $number; ?>
  </div>
  <div class="wins">
    <span> <?php echo t('Wins'). ': '; ?> </span>
    <?php echo $wins; ?>
  </div>
  
  <div class="salary">
    <span><?php echo t('Salary'). ': '; ?> </span>
    <?php echo $salary; ?>
  </div>
</div>
