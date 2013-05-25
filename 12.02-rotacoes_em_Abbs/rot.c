/* prog 12.11 */
/*   
 *     h                    x      
 *    ( )       rotL(h)      ( )   
 *    / \        --->        / \   
 *   /   \x      <---      h/   \  
 * | |   [ ]    rotR(x)   [ ]   | |
 * |A|   / \              / \   |C|
 * | | | | | |          | | | | | |
 *     |B| |C|          |A| |B|   
 *     | | | |          | | | |    
 */ 

link rotR(link x)
{ link h = x->l; x->l = h->r;
  h->r = x; return h; }

link rotL(link h)
{ link x = ->r; h->r = x->l;
  x->l = h; return x; }
