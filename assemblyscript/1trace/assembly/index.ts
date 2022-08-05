// const blockOffset = 3 * sizeof<u32>() * 8;
// const AL_BITS: u32 = 4; // 16 bytes to fit up to v128
// // @ts-ignore: decorator
// const AL_SIZE: usize = 1 << <usize>AL_BITS;
// // @ts-ignore: decorator
// const AL_MASK: usize = AL_SIZE - 1;


// class ll_head {
//   prev: usize;//prev pointer
//   next: usize;//next pointer
// }
// class Block {
//   prev: usize;//prev pointer
//   next: usize;//next pointer
//   size: u32;
// };
// var freeList: ll_head;

// function align_up(num: u32): u32 {
//   return ((num) + ((1 << alignof<usize>()) - 1)) & ~((1 << alignof<usize>()) - 1);
// }

// function m_malloc(size: u32): usize {

//   size = align_up(size);
//   let result: u32 = 0;
//   let block: Block = changetype<Block>(freeList);
//   for (let pos: ll_head = changetype<ll_head>(freeList.next);
//     changetype<usize>(pos) != changetype<usize>(freeList);
//     pos = changetype<ll_head>(pos.next)) {
//     block = changetype<Block>(changetype<usize>(pos));
//     if (block.size > size) {
//       break;
//     }
//   }
//   if (changetype<usize>(block) != changetype<usize>(freeList)) {// found
//     if (block.size - size > 8 + sizeof<Block>()) {
//       const newBlockPtr: usize = changetype<usize>(block) + sizeof<Block>() + size;
//       let newBlock: Block = changetype<Block>(newBlockPtr);
//       newBlock.size = block.size - sizeof<Block>() - size;
//       block.size = size;
//       let blockNextBlock: Block = changetype<Block>(block.next);
//       //insert block
//       block.next = changetype<usize>(newBlock);
//       newBlock.prev = changetype<usize>(block);
//       newBlock.next = changetype<usize>(blockNextBlock);
//       blockNextBlock.prev = changetype<usize>(newBlock);
//     }
//     //delete block  from freelist
//     let blockNextBlock: Block = changetype<Block>(block.next);
//     let blockPrevBlock: Block = changetype<Block>(block.prev);
//     blockPrevBlock.next = changetype<usize>(blockNextBlock);
//     blockNextBlock.prev = changetype<usize>(blockPrevBlock);
//     block.next = 0;
//     block.prev = 0;
//   } else {//TODO: add more block

//   }
//   return changetype<usize>(block) + sizeof<Block>();
// }

// function deflagFreeList():void {
//   let prevBlock: Block | null = null;
//   for (
//     let pos = changetype<Block>(freeList.next), temp = changetype<Block>(pos.next);
//     changetype<usize>(pos) != changetype<usize>(freeList);
//     pos = temp, temp = changetype<Block>(temp.next)
//   ) {
//     if (prevBlock) {
//       if (changetype<usize>(prevBlock) + sizeof<Block>() + prevBlock.size == changetype<usize>(pos)) {
//         prevBlock.size += sizeof<Block>() + pos.size;
//         //delete pos
//         let prevB = changetype<Block>(pos.prev);
//         let nextB = changetype<Block>(pos.next);
//         prevB.next = changetype<usize>(nextB);
//         nextB.prev = changetype<usize>(prevB);
//         pos.prev = 0;
//         pos.next = 0;
//       }
//       continue;
//     }
//     prevBlock = pos;
//   }
// }

// function m_free(ptr: usize): usize {
//   const currentBlockPtr = ptr - sizeof<Block>();
//   let currentBlock = changetype<Block>(currentBlockPtr);
//   let alreadyInsert: bool = false;
//   for (let pos: ll_head = changetype<ll_head>(freeList.next);
//     changetype<usize>(pos) != changetype<usize>(freeList);
//     pos = changetype<ll_head>(pos.next)) {
//     let block = changetype<Block>(changetype<usize>(pos));
//     if (changetype<usize>(pos) > currentBlockPtr) {
//       let prevBlock = changetype<Block>(block.prev);
//       prevBlock.next = currentBlockPtr;
//       currentBlock.prev = changetype<usize>(prevBlock);
//       currentBlock.next = changetype<usize>(block);
//       block.prev = currentBlockPtr;
//       alreadyInsert = true;
//       break;
//     }
//   }
//   if (!alreadyInsert) {// add to tail
//     let prevBlock = changetype<Block>(freeList.prev);
//     freeList.prev = currentBlockPtr;
//     prevBlock.next = currentBlockPtr;
//     currentBlock.next = changetype<usize>(freeList);
//     currentBlock.prev = changetype<usize>(prevBlock);
//   }
//   //merge free list
//   deflagFreeList();
//   return changetype<usize>(freeList);
// }

// function initialize(): void {
//   // 0x____0000 as start pointer
//   //capacity is memory.size() << 16
//   const startPoint: usize = (__heap_base + AL_MASK) & ~AL_MASK;
//   const pagesBefore = memory.size();
//   //init 65536 size 
//   const pagesNeeded = <i32>((((startPoint + 1) + 0xffff) & ~0xffff) >>> 16);
//   if (pagesNeeded > pagesBefore && memory.grow(pagesNeeded - pagesBefore) < 0) unreachable();
//   freeList = changetype<ll_head>(startPoint);
//   freeList.next = startPoint;
//   freeList.prev = startPoint;
//   let cursor = startPoint + offsetof<ll_head>();
//   let block: Block = changetype<Block>(cursor);
//   freeList.next = cursor;
//   freeList.prev = cursor;
//   block.prev = startPoint;
//   block.next = startPoint;
//   block.size = ((pagesNeeded - pagesBefore) << 16) - (offsetof<ll_head>() + offsetof<Block>());
// }

function templateFun(strings:Array<string>, number:i32):string{
  return strings[0] + number.toString();
}

export function add(size: u32): usize {
  // if (!freeList) (initialize());
  // let ptr = m_malloc(5);
  // m_free(ptr);
  // return load<usize>(changetype<usize>(freeList) + 4*sizeof<usize>());
  trace("trace", 1, 42);
  return 0;
}

