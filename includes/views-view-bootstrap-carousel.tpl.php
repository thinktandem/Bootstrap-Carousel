<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div id="<?php print $carousel_id; ?>" class="carousel slide"<?php print $attributes; ?>>
	<div class="carousel-inner">
	<?php foreach ($rows as $id => $row): ?>
		<?php $active = $id == 0 ? 'active' : ''; ?>
	  <div <?php if ($classes_array[$id]) { print 'class="' . $classes_array[$id] . ' ' . $active . ' item ' . $bootstrap_container . '"';  } ?>>
	    <?php print $row; ?>
	  </div>
	<?php endforeach; ?>
	</div>
	<a class="carousel-control left" href="#<?php print $carousel_id; ?>" data-slide="prev">&lsaquo;</a>
  <a class="carousel-control right" href="#<?php print $carousel_id; ?>" data-slide="next">&rsaquo;</a>
</div>
